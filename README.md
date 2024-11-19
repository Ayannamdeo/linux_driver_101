# Install OpenSSH and configure ssh

```
sudo apt update
sudo apt install OpenSSH-server
sudo systemctl start ssh
sudo systemctl enable ssh
sudo apt install vim
vim /etc/ssh/sshd_config
```

change line 62 to yes

```
sudo systemctl daemon-reload
sudo service ssh restart
hostname -I
```

# SSH into VM

`ssh -v guestname@guestIPaddress`

# Make commands

```
make all
make clean
modinfo ldd.ko
```

# Kernel commands

```
sudo insmod ldd.ko
sudo rmmod ldd
sudo dmesg -c
lsmod
cat /proc/ayan_drivder_101
echo "something" | sudo tee /proc/ayan_drivder_101
```
