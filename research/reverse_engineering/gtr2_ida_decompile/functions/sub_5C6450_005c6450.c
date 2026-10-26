void __thiscall sub_5C6450(int *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // ecx
  double v5; // st7
  float *v6; // ecx
  float *v7; // ecx
  int v8; // ecx
  float v9; // [esp+8h] [ebp-4h]

  v2 = *this;
  if ( *this > 0 )
  {
    v9 = *(float *)(this[2] + 4);
    if ( v9 > 0.0 )
    {
      v3 = 0;
      if ( v2 >= 4 )
      {
        do
        {
          *(float *)(this[2] + 8 * v3 + 4) = *(float *)(this[2] + 8 * v3 + 4) - v9;
          *(float *)(this[2] + 8 * v3 + 12) = *(float *)(this[2] + 8 * v3 + 12) - v9;
          *(float *)(this[2] + 8 * v3 + 20) = *(float *)(this[2] + 8 * v3 + 20) - v9;
          v4 = this[2];
          v5 = *(float *)(v4 + 8 * v3 + 28);
          v6 = (float *)(v4 + 8 * v3 + 28);
          v3 += 4;
          *v6 = v5 - v9;
        }
        while ( v3 < v2 - 3 );
      }
      for ( ; v3 < v2; *v7 = *v7 - v9 )
        v7 = (float *)(this[2] + 8 * v3++ + 4);
    }
  }
  v8 = this[3];
  if ( v8 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 8))(v8);
  *((_BYTE *)this + 30) = 1;
}
