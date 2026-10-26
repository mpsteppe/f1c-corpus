// f1c  0x0057b550  size=98
char __thiscall sub_57B550(int this, int a2, int a3)
{
  int v3; // edx
  int v5; // eax
  int v6; // esi
  int v7; // edi
  int v8; // edx
  char v9; // bl

  v3 = *(unsigned __int16 *)(this + 4098);
  if ( (unsigned __int16)v3 + a3 > 4096 )
    return 0;
  v5 = v3 + *(__int16 *)(this + 4096);
  if ( a3 > 0 )
  {
    v6 = a2 - v5;
    v7 = a3;
    do
    {
      v8 = v5 % 4096;
      v9 = *(_BYTE *)(v6 + v5++);
      --v7;
      *(_BYTE *)(v8 + this) = v9;
    }
    while ( v7 );
  }
  *(_WORD *)(this + 4098) += a3;
  return 1;
}
