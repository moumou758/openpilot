#include "selfdrive/ui/qt/onroad/buttons.h"

#include <QPainter>

#include "selfdrive/ui/qt/util.h"

// 修改后的 drawIcon，支持传入 angle 并旋转图标
void drawIcon(QPainter &p, const QPoint &center, const QPixmap &img, const QBrush &bg, float opacity, int angle = 0) {
  p.setRenderHint(QPainter::Antialiasing);
  p.setOpacity(0.6);  // bg dictates opacity of ellipse
  p.setPen(Qt::NoPen);
  p.setBrush(bg);
  p.drawEllipse(center, btn_size / 2, btn_size / 2);

  p.save();
  p.translate(center);
  p.rotate(angle);
  p.setOpacity(opacity);
  p.drawPixmap(-QPoint(img.width() / 2, img.height() / 2), img);
  p.setOpacity(0.6);
  p.restore();
}

// ExperimentalButton
ExperimentalButton::ExperimentalButton(QWidget *parent)
    : experimental_mode(false), engageable(false), steering_angle_deg(0), QPushButton(parent) {
  setFixedSize(btn_size, btn_size);

  engage_img = loadPixmap("../assets/img_chffr_wheel.png", {img_size, img_size});
  experimental_img = loadPixmap("../assets/img_experimental.svg", {img_size, img_size});
  QObject::connect(this, &QPushButton::clicked, this, &ExperimentalButton::changeMode);
}

void ExperimentalButton::changeMode() {
  const auto cp = (*uiState()->sm)["carParams"].getCarParams();
  bool can_change = (hasLongitudinalControl(cp) || (!cp.getPcmCruiseSpeed() && params.getBool("CustomStockLongPlanner")))
                    && params.getBool("ExperimentalModeConfirmed");
  if (can_change) {
    params.putBool("ExperimentalMode", !experimental_mode);
  }
}

void ExperimentalButton::updateState(const UIState &s) {
  const auto cs = (*s.sm)["controlsState"].getControlsState();
  bool eng = cs.getEngageable() || cs.getEnabled();
  int new_steering_angle = s.scene.steering_angle_deg;  // 注意这里是你车辆状态里同步的方向盘角度
  if ((cs.getExperimentalMode() != experimental_mode) || (eng != engageable) ||
      (steering_angle_deg != new_steering_angle)) {
    engageable = eng;
    experimental_mode = cs.getExperimentalMode();
    steering_angle_deg = new_steering_angle;
    update();
  }
}

// 注意这里 paintEvent 传入角度
void ExperimentalButton::paintEvent(QPaintEvent *event) {
  QPainter p(this);
  QPixmap img = experimental_mode ? experimental_img : engage_img;
  drawIcon(p, QPoint(btn_size / 2, btn_size / 2), img, QColor(0, 0, 0, 166),
           (isDown() || !engageable) ? 0.5 : 0.6, steering_angle_deg);
}
