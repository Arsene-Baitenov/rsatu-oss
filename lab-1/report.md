# PC Specifications

## PC
MacBook Air M1, 2020

## CPU
name: `Apple M1`

high-performance cores number: `4`

energy-efficient cores number: `4`

### Perfomance levels specifications

#### Perfomance level
Command:
```sh
sysctl -a | grep hw.perflevel0
```
Output:
```
hw.perflevel0.physicalcpu: 4
hw.perflevel0.physicalcpu_max: 4
hw.perflevel0.logicalcpu: 4
hw.perflevel0.logicalcpu_max: 4
hw.perflevel0.l1icachesize: 196608
hw.perflevel0.l1dcachesize: 131072
hw.perflevel0.l2cachesize: 12582912
hw.perflevel0.cpusperl2: 4
hw.perflevel0.name: Performance
```
#### Efficiency level
Command:
```sh
sysctl -a | grep hw.perflevel1
```
Output:
```
hw.perflevel1.physicalcpu: 4
hw.perflevel1.physicalcpu_max: 4
hw.perflevel1.logicalcpu: 4
hw.perflevel1.logicalcpu_max: 4
hw.perflevel1.l1icachesize: 131072
hw.perflevel1.l1dcachesize: 65536
hw.perflevel1.l2cachesize: 4194304
hw.perflevel1.cpusperl2: 4
hw.perflevel1.name: Efficiency
```

### Features flags
Command:
```sh
sysctl -a | grep hw.optional
```
Partial output:
```
hw.optional.floatingpoint: 1
```

## RAM
Size: `8 GB`

Type: `LPDDR4`

Manufacturer: `Hynix`

## Storage
Capacity: `45,11 GB`

File system: `APFS`

Type of physical disk: `SSD`