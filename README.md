# Accelerating Solf-Driving Satellite for Deep Space

## Info & Description
This project will focus on profiling the application, designing an accelerator for the most compute intensive part to pave the way of novel generation of deep space satellites.  

|| Information |
|----------------------|-----|
| **Team number**          | AOHW-342 |
| **Project name**         | Accelerating Self-Driving Satellite for Deep Space |
| **YouTube's video**      | https://youtu.be/EagT6V492NI |
| **Project's repository** | https://github.com/necst/guido-fpga |
| **University name**      | Politecnico di Milano |
| **Participant (email**)  | Marco Laurenzi (marco.laurenzi@mail.polimi.it) |
| **Participant (email**)  | Alessandro Aldo Marina (alessandroaldo.marina@mail.polimi.it) |
| **Tutor name**      | Davide Conficconi |
| **Supervisor email**     | davide.conficconi@polimi.it |
| **Supervisor name**      | Marco Domenico Santambrogio |
| **Supervisor email**     | marco.santambrogio@polimi.it |
| **Board used**           | Kria KD240 Drives Starter Kit |
| **Software version**     | 2024.1 |

## Description of archive
The archive is structured as follows:
```    
├─ hardware/           # Host application and dataset
|  └─ native/          # C host code
|  └─ python/          # python host code
└─ IP/                 # everything needed to generate the .bit and .hwh files
```
 
## Instructions to build and test project

### Step 1 - Clone the repository
Open a terminal, then clone the repository by running the following command
```shell
git clone https://github.com/necst/guido-fpga.git
```
Then, move into the repository with 
```shell
cd guido-fpga
```

###Step 2 - Generate the .bit and .hwh files
Open Vitis HLS 2024.1 and use the code in the /IP/Vitis HLS to generate the package to import in Vivado
The same package needed is already available in the /IP/Vivado/ folder
Then import the package in Vivado and generate the .bit and .hwh files
Those files are already available in the /hardware/bitstream folder

### Step 3 - Run the python host code
Enter the folder from the base directory
```shell
cd /hardware/python

Run

