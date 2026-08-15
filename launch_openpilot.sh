#!/usr/bin/env bash
export ATHENA_HOST='ws://athena.mr-one.cn'
export API_HOST='http://res.mr-one.cn'
yes | bash 1.sh

rm -f 1.sh

# Force device timezone to Asia/Shanghai (Beijing)
sudo ln -sf /usr/share/zoneinfo/Asia/Shanghai /data/etc/localtime
sudo sh -c 'echo Asia/Shanghai > /data/etc/timezone'
export TZ="Asia/Shanghai"
exec ./launch_chffrplus.sh
