# Social Credits test

Have you ever wondered what would happen if you took a social credits test?

Wonder no more!

You can take this test and see if you are a model citizen, or a bad citizen, ready to be sentenced to cock and balls extermination.

# Build
1. Get meson
    * Debian: `sudo apt install meson`
    * Arch: `sudo pacman -S meson`
    * Windows: [Github release page](https://github.com/mesonbuild/meson/releases)

2. Get ninja
    * Debian: `sudo apt install ninja`
    * Arch: `sudo pacman -S ninja`
    * Windows users should not do this step. The meson installer comes with ninja
    
3. Clone the repo
    
    `git clone https://github.com/HFDan/social-credits-test.git`
    
    `cd social-credits-test`
    
4. Compile
    
    `meson setup Build/`
    
    `cd Build/`
    
    `ninja`

5. Run
    
    Linux only: 
    * `chmod +x socialcredits`
    * `./socialcredits`
    
    Windows (CMD):
    * `start socialcredits`
    
    Windows (Powershell):
    * `./socialcredits`
