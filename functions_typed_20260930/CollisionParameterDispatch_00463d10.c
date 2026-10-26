char __stdcall sub_463D10(int a1, int a2)
{
  float v3; // [esp+0h] [ebp-Ch]

  v3 = dbl_8AFEA0;
  CollisionStateUpdate(LODWORD(v3), a2, *((float *)&MEMORY[0x5F0708] + 4656 * a1));
  return 1;
}

