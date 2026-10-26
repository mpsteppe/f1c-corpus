// f1c  0x0047b910  size=172
int __thiscall sub_47B910(_DWORD **this, int a2, int a3, int a4)
{
  char *v4; // edi
  int v5; // esi
  bool v6; // zf
  int v7; // ebp
  char v8; // bl
  char *v9; // eax
  int v11; // [esp+10h] [ebp-Ch]
  char v12[4]; // [esp+18h] [ebp-4h] BYREF

  v4 = (char *)*this[56];
  if ( !v4 )
    v4 = byte_5EA438;
  v5 = a3 + 1;
  v6 = a3 + 1 == a4;
  v11 = 0;
  if ( a3 + 1 < a4 )
  {
    v7 = a2;
    while ( 1 )
    {
      v8 = v4[v5];
      v9 = &v4[a3];
      v4[v5] = 0;
      sub_4983B0(v9, &a2, v12, 1);
      v4[v5] = v8;
      if ( v7 <= a2 )
        break;
      v11 = a2;
      if ( ++v5 >= a4 )
        goto LABEL_10;
    }
    if ( v7 <= (v11 + a2) / 2 )
      --v5;
LABEL_10:
    v6 = v5 == a4;
  }
  if ( v6 && v5 > a3 && v4[v5] )
    --v5;
  return v5;
}
