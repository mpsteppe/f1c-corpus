void __thiscall sub_528960(int *this, int a2, int a3)
{
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // ebx
  int v8; // ebp
  int i; // edx
  int v10; // eax
  int v11; // ecx

  v4 = this[722649];
  v5 = this[722650];
  if ( v4 >= v5 )
  {
    if ( v4 < 0 || v5 < 0 )
      goto LABEL_8;
    v6 = v4 - v5 + 1;
  }
  else
  {
    v6 = this[722648] - v5 + v4 + 1;
  }
  if ( v6 == 1 && !*(_BYTE *)(184 * v5 + this[722647]) )
LABEL_8:
    v6 = 0;
  v7 = v6;
  if ( !v6 )
  {
    sub_527E30(this, *(float *)&a3);
    v7 = sub_521F70();
  }
  v8 = 0;
  if ( v7 > 0 )
  {
    for ( i = this[722649]; ; --i )
    {
      v10 = i;
      if ( i < 0 )
        v10 = i + this[722648];
      v11 = this[722647] + 184 * v10;
      if ( *(float *)(v11 + 116) <= (double)*(float *)(a2 + 4) )
        break;
      if ( ++v8 >= v7 )
        return;
    }
    if ( *(float *)(a2 + 4) - *(float *)(v11 + 116) < 1.5 )
      sub_525BB0((_BYTE *)v11, (_DWORD *)a2, a3);
  }
}
