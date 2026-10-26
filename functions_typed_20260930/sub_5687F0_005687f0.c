char __thiscall sub_5687F0(void *this)
{
  int v1; // ecx
  char v2; // al
  int v3; // esi
  _BYTE v5[8]; // [esp+0h] [ebp-64h] BYREF
  _DWORD v6[23]; // [esp+8h] [ebp-5Ch]

  v6[0] = &off_5E5230;
  v6[1] = aPrn;
  v6[2] = &off_5D4D10;
  v6[3] = aClock;
  v6[4] = aCom1;
  v6[5] = aCom2;
  v6[6] = aCom3;
  v6[7] = aCom4;
  v6[8] = aCom5;
  v6[9] = aCom6;
  v6[10] = aCom7;
  v6[11] = aCom8;
  v6[12] = aCom9;
  v6[13] = aLpt1;
  v6[14] = aLpt2;
  v6[15] = aLpt3;
  v6[16] = aLpt4;
  v6[17] = aLpt5;
  v6[18] = aLpt6;
  v6[19] = aLpt7;
  v6[20] = aLpt8;
  v6[21] = aLpt9;
  v6[22] = &off_5E5190;
  sub_587DD0(v5, this, 7);
  v5[7] = 0;
  v1 = 0;
  while ( 1 )
  {
    v2 = v5[v1];
    if ( v2 == 92 || v2 == 47 || v2 == 58 || v2 == 46 )
      break;
    if ( (unsigned int)++v1 >= 8 )
      goto LABEL_9;
  }
  v5[v1] = 0;
LABEL_9:
  v3 = 0;
  while ( sub_588410(v5, v6[v3]) )
  {
    if ( ++v3 >= 23 )
      return 0;
  }
  return 1;
}

