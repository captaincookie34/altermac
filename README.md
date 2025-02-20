# altermac
- Taking inspiration from CS456, I made this simple MAC Address Changer for your device.

# NOTE:
- I would suggest downloading and running this script in a virtual machine
- You would also need to use root permissions to run this script

# Sample Usage:
```bash
make clean
make
sudo ./altermac eth0
```
- The above command changes the MAC address of your eth0 interface
- Looking at the `eth0` interface by running `ifconfig`, you should be able to see that the MAC address under `ether` has changed

## Working

```bash
strace -f ifconfig eth0 hw ether <NEW MAC ADDR> 2> output.txt
```
- You can use the above command to take a look at the functions and libraries called and undrestand how the command works
- Although the above command changes the MAC address, this project mimics the behind the scenes working of the above command
- A sample output is provided in the `output.txt` file


- Specifically, you would see that the following command was responsible for changing the MAC address:
```bash
ioctl(4, SIOCSIFHWADDR, {ifr_name="eth0", ifr_hwaddr={sa_family=ARPHRD_ETHER, sa_data=<New-MAC>}}) = 0
```