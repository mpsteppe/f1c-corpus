// Function: FUN_00464f90 @ 00464f90
// Size (bytes): 64


char FUN_00464f90(int param_1)

{
  if (param_1 < 0x5d0) {
    return '\0';
  }
  if (param_1 < 0xba0) {
    return '\x01';
  }
  if (param_1 < 0x1c21) {
    return '\x02';
  }
  return (0x7080 < param_1) + '\x03';
}


