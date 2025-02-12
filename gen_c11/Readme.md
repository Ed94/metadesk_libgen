# gen_c11

[gen_c11.c](./gen_c11.c) generates both *segregated* and *single-header* varients of the metadesk library utilizing [gencpp_c11](../third_party/gencpp_c11/).

Generated content will be place in a subdirectory called `/gen`.

[gen_common.h](./gen_common.h) contains implementation that will eventually be utilized by [gen_cpp17](../gen_cpp17/).

If using the powershell script [build.ps1](../bin/build.ps1); Use the following command:

```ps1
.\build gen_c11 <debug> <msvc>
```
