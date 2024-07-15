# Rhymestone Config

This is just a repository in order to save my own personal config for the [Rhymestone](https://github.com/marksard/Keyboards?tab=readme-ov-file#rhymestone)
![Rhymestone](./rhymestone.jpg)

## How to use
Install the QMK Firmware https://github.com/qmk/qmk_firmware

Then clone this repository into the correct place like so
```
# presumed to be in the qmk firmware directory
git clone https://github.com/meir/rhymestone-config ./keyboards/marksard/rhymestone/keymaps/meir
```

And then compile and flash
```
qmk compile -c -kb marksard/rhymestone -km meir
qmk flash -kb marksard/rhymestone -km meir
```

If you have a blok controller, add `-e CONVERT_TO=blok` to the compile command.

