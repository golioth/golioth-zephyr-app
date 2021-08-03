# Example Application for Golioth + Zephyr on the ESP32

This example shows how to use Golioth on Zephyr for the ESP32. This particular app just logs an incrementing counter
to Golioth's logging service.

## Setup

1. Create a workspace directory:

```console
mkdir golioth-demo
cd golioth-demo
```

2. Create a virtual environment and activate it (recommended, but not necessary)

```console
python3 -m venv .venv
source .venv/bin/activate
```

If you're using another shell, like `fish`, `source` the `activate` binary that corresponds to your shell, e.g. `source .venv/bin/activate.fish`.

3. Install west

```console
pip3 install west
```

4. Pull down this example:

```console
west init -m git@github.com:golioth/golioth-zephyr-app.git --manifest-rev main
```

or if you've already cloned it

```console
west init -l example-zephyr-app
```

5. Once it's cloned, `cd` to the `golioth-zephyr-app` directory and run `west update`:

```console
west update
```
6. Install the remaining requirements:

```console
pip3 install -r zephyr/scripts/requirements.txt
```

## Running the Example Application

1. `cd` to the `golioth-zephyr-app/app` directory:

```console
cd golioth-zephyr-app/app
```

2. If you're **not** using the Zephyr SDK (which automatically sets up the toolchain):

```console
export ZEPHYR_TOOLCHAIN_VARIANT="espressif"
export ESPRESSIF_TOOLCHAIN_PATH="~/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/"
export PATH="$PATH:$ESPRESSIF_TOOLCHAIN_PATH/bin"
```

The `ESPRESSIF_TOOLCHAIN_PATH` could be different, depending on your OS, installation process, and toolchain version.

3. Add your credentials to this application:

Take a look at the [`prj.conf`](app/prj.conf) file and take note of the four lines at the end.
Fill in `CONFIG_GOLIOTH_SYSTEM_CLIENT_PSK_ID` and `CONFIG_GOLIOTH_SYSTEM_CLIENT_PSK` with the credentials you've generated with Golioth
and `CONFIG_ESP32_WIFI_SSID` and `CONFIG_ESP32_WIFI_PASSWORD` with your WiFi's SSID and passphrase.

4. Build it:

```console
west build -b esp32 .
```

5. Flash it:

```console
west flash --esp-device=<path to the USB device>
```
