# Example Application for Golioth + Zephyr on the ESP32

This example shows how to use Golioth on Zephyr for the ESP32. This particular app just logs an incrementing counter
to Golioth's logging service.

## Setup

1. Creating a workspace directory:

```console
mkdir golioth-demo
cd golioth-demo
```

2. Create a virtual environment and activate it (recommended, but not necessary)

```console
python3 -m venv .venv
source .venv/bin/activate
```

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
cd golioth-demo/golioth-zephyr-app/app
```

2. If you're **not** using the Zephyr SDK (which automatically sets up the toolchain):

```console
export ZEPHYR_TOOLCHAIN_VARIANT="espressif"
export ESPRESSIF_TOOLCHAIN_PATH="~/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/" # This path could be different
export PATH="$PATH:$ESPRESSIF_TOOLCHAIN_PATH/bin"
```

3. Build it:

```console
west build -b esp32 .
```

4. Flash it:

```console
west flash --esp-device=<path to the USB device>
```
