# net_notice
generates notices
This tool is designed to detect connection failures when using the Linux wpa_supplicant and then take action to remediate the issue.
External Library: curl
Operating System: Linux
Language: C
OS Packages: libcurl4-openssl-dev
Package manager commands: {apt: sudo apt-get install libcurl4-openssl-dev}

Build instructions
gcc n3tm0n -o n3tm0n

Service instructions
clone the project into /opt/

cp n3tm0n.service /etc/systemd/system

systemctl daemon-reload
systemctl enable n3tm0n.service
systemctl start n3tm0n.service
systemctl status n3tm0n.service
