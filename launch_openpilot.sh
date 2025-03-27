#!/usr/bin/bash
export ATHENA_HOST='ws://laolang.duckdns.org:7899'
export API_HOST='http://laolang.duckdns.org:7898'
export MAPBOX_TOKEN='pk.eyJ1Ijoiam5ld2IiLCJhIjoiY2xxNW8zZXprMGw1ZzJwbzZneHd2NHljbSJ9.gV7VPRfbXFetD-1OVF0XZg'
export SKIP_FW_QUERY=1
exec ./launch_chffrplus.sh
