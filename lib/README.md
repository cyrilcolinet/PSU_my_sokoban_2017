# :shell: C Library - Used everything (only c projects)

This C library contains all the basic C functions like printf, strcat, etc...

# :computer: Compilation

To compile, go into your project root folder, and make:

```
git clone https://github.com/mrlizzard/CPE_my_library.git lib
```

> :bulb: If you want to clone with the **ssh** protocol, replace the `https` link by `ssh`.
>
> Command with ssh link: ```git clone git@github.com:mrlizzard/CPE_my_library.git lib```

After clone, do this commands:

```
mkdir -p include
make -C ./lib
```

And if you see ```Library successfully compiled.```, ```Header(s) and static library(ies) copied.``` and the file `my.h` have been in your `include` folder, all is compiled and you can use the library by including the following flags in your C compilation:

```
-L./lib -lmy -I./include
```

> :exclamation: This library is in continuous integration and some functions may be broken...

> :exclamation: Some functions are not adapted to **EPITECH C CODING STYLE 2017**, but... Soon :tongue: 