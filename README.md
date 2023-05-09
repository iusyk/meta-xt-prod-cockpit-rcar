# meta-xt-prod-cockpit-rcar - Demo product with advanced HMP technologies
meta-xt-prod-cockpit-rcar

This repository contains Renesas RCAR Gen3-specific Yocto layers for
Xen Troops demo and moulin project file to build it. Layers in this
repository provide final recipes to build meta-xt-prod-cockpit-rcar demo.
This demo is the main Xen Troops product, that we use to develop and
integrate new features

Those layers may be added and used manually, but they were written
with [Moulin](https://moulin.readthedocs.io/en/latest/) build system,
as Moulin-based project files provide correct entries in local.conf

# Moulin project file

Features that are present :
* Kingfisher with Starter Kit Premiere 8GB board
* SD or eMMC boot
* Android VM support

# Building
## Requirements

1. Ubuntu 18.0+ or any other Linux distribution which is supported by Poky/OE
2. Development packages for Yocto. Refer to Yocto manual.
3. You need Moulin installed in your PC. Recommended way is to install it for your user only: pip3 install --user git+https://github.com/xen-troops/moulin. Make sure that your PATH environment variable includes ${HOME}/.local/bin.
4. Ninja build system: sudo apt install ninja-build on Ubuntu

## Fetching

You can fetch/clone this whole repository, but you actually need only one file from it: prod-cockpit-rcar.yaml. During build moulin will fetch this repository again into yocto/ directory. So, to reduce possible confuse, we recommend to download only prod-cockpit-rcar.yaml:

```
# curl -O https://raw.githubusercontent.com/xen-troops/meta-xt-prod-cockpit-rcar/master/prod-cockpit-rcar.yaml
```

## Building

Moulin is used to generate Ninja build file: moulin prod-cockpit-rcar.yaml. This project have provides number of additional options. You can use check them with --help-config command line option:

```
# moulin prod-cockpit-rcar.yaml --help-config
Usage: moulin prod-cockpit-rcar.yaml --MACHINE h3ulcb-4x2g-kf
                   [--ENABLE_ANDROID yes] 
                   [--ENABLE_CLUSTER yes]
		   [--PREBUILT_DDK {no,yes}]
		   [--ANDROID_PREBUILT_DDK {no,yes}]
       
Config file description: Xen-Troops development setup for Renesas RCAR Gen3
hardware

optional arguments:
  --MACHINE {h3ulcb-4x2g-kf}
                        RCAR Gen3-based device
  --ENABLE_ANDROID {no,yes}
                        Build Android as a guest VM. Default value is 'no'
  --ENABLE_CLUSTER {no,yes}
                        Build Instrument Cluster application.
  --ENABLE_TOOLS {no. yes}
  			Build the tool (cr7-image-gen). This application
			allows generating the source files from the list of the images 
			required for cr7.
  --DISPLAY {lvds, hdmi}
                        Build image for lvds or hdmi display.
			Default value is 'lvds'
                        Build Instrument Cluster application.Default value is 'no'
  --PREBUILT_DDK {no,yes}
                        Use pre-built GPU drivers. Default value is 'no'
  --ANDROID_PREBUILT_DDK {no,yes}
                        Use pre-built GPU drivers for Android. Default value is 'no'.

```

To built for Kingfisher with Starter Kit Premiere 8G with DomA (generic yocto-based virtual machine) use the following command line: `moulin prod-cockpit-rcar.yaml --MACHINE h3ulcb-4x2g-kf --ENABLE_ANDROID yes.`

Moulin will generate `build.ninja` file. After that - run `ninja` to build the images. This will take some time and disk space, as it will built 3 separate Yocto images.

This will require even more time and space, as Android is quite big.

## Building with prebuilt graphics for DomD

Regular build, as described above, requires access to closed repo
with proprietary sources. But you may use prebuilt graphics binaries.
Please see instruction below.

1. You need to have prebuilt graphic binaries. Pay attention that you
can't use prebuilt binaries from Renesas because those packages
do not support virtualization.
2. Put these binaries into `<directory_with_yaml>/../prebuilt_gsx/`.
By default prebuilt binaries are expected to be in the dedicated folder
on the same level as your folder with yaml. But this can be changed in
yaml file. Provide your directory in line
```
          XT_PREBUILT_GSX_DIR: "${TOPDIR}/../../prebuilt_gsx"
```
Here we use the yocto variable `${TOPDIR}`. You may use yaml's variables
like `%{YOCTOS_WORK_DIR}`, but pay attention that `%` should be used when
referring to variables defined inside yaml. Also, you may provide an
absolute path on your build host.

During build each domain will look for its binaries inside the directory
with its name - "domd". This name is specified by variable
`%{XT_DOM_NAME}` in yaml for each domain.

So, by default, you should have `domd` folder with archives
under `prebuilt_gsx`. It looks like this:
```
prebuilt_gsx/
  domd/
    GSX_KM_H3.tar.bz2
    r8a77951_linux_gsx_binaries_gles.tar.bz2
<your work directory with prod-devel-rcar.yaml and build.ninja generated by moulin>
  prod-devel-rcar.yaml
  build.ninja
  <... other build related files and directories ...>
```

3. Use `--PREBUILT_DDK yes` command line option for moulin.

Run build as usual with `ninja`.


Prior to running moulin, you need to place android graphics prebuilts
archive `rcar-prebuilts-graphics-xt-doma.tar.gz` in the same directory
as yaml file.

Use `--ANDROID_PREBUILT_DDK yes` commad line option for moulin.

## Creating SD card image

Image file can be created with rouge `rouge`. This is a companion application for `moulin`.

It can be invoked either as a standalone tool, or via Ninja.

### Creating image(s) via Ninja

Newer versions of moulin (>= 0.5) will generate two additional Ninja targets:

 - `image-full`
 - `image-android_only` (if building with `--ENABLE_ANDROID=yes`)

Thus, you can just run `ninja image-full` or `ninja full.img` which will generate the `full.img` in your build directory.

Then you can use `dd` to write this image to your SD card. Don't forget `conv=sparse` option for `dd` to speed up writing.

### Using `rouge` in standalone mode

In this mode you can write image right to SD card. But it requires additional options.

In standalone mode`rouge` accepts the same parameters like
`--MACHINE`, `--ENABLE_ANDROID` as `moulin` do.

This XT product provides two images: `full` and `android_only`. Latter
is available only when `--ENABLE_ANDROID=yes`.

You can prepare image by running

```
# rouge prod-cockpit-rcar.yaml --ENABLE_ANDROID=yes -i full
```

This will create file `full.img` in your current directory.

Also you can write image directly to a SD card by running

```
# sudo rouge prod-devel-rcar.yaml --ENABLE_ANDROID=yes -i full -so /dev/sdX
```

**BE SURE TO PROVIDE CORRECT DEVICE NAME**. `rouge` have no
interactive prompts and will overwrite your device right away. **ALL
DATA WILL BE LOST**.

If you want to generate only Android sub-image use `-i android_only`
option.

For more information about `rouge` check its
