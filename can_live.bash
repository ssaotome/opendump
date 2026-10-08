#!/bin/bash
if ip link show can0 &> /dev/null; then
    echo "can0 device exists"
else
    echo "ERROR can0 device does not exist"
    exit 1
fi

state=$(ip -details link show can0 | grep -o 'state [A-Z-]*')
echo "state is $state"

ip link set can0 down
state=$(ip -details link show can0 | grep -o 'state [A-Z-]*')
echo "reset, state should be DOWN now = $state"

ip link set can0 up type can bitrate 500000
state=$(ip -details link show can0 | grep -o 'state [A-Z-]*')
echo "state should be UP bitrate 500000 state now = $state"
echo "state ERROR-ACTIVE means healthy"

#chmod +x can_live.bash (enable this bash script)
#sudo ./can_live.bash (run)


