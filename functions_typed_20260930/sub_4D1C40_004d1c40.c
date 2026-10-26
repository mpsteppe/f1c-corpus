char __thiscall sub_4D1C40(_BYTE *this, int a2, int a3, char a4)
{
  int v5; // ecx
  int v6; // eax

  if ( a4 )
    goto LABEL_6;
  v5 = (unsigned __int8)this[a2 + 400];
  if ( v5 >= dword_5C329C
    || (v6 = a2 + 4656 * a3, MEMORY[0x5F0774][v6] != -1.0)
    && MEMORY[0x5F0774][4656 * v5 + a2] >= (double)MEMORY[0x5F0774][v6] )
  {
    AIOvertakeDefendStateChange(dword_5EB978, a2, a3, (unsigned __int8)this[a2 + 400]);
LABEL_6:
    this[a2 + 400] = a3;
    return 1;
  }
  return 0;
}

