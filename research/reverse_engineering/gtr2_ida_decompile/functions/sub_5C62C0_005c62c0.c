void __thiscall sub_5C62C0(int *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // eax
  unsigned int v5; // edx
  int v6; // ecx
  double v7; // st7
  float *v8; // ecx
  int v9; // eax
  int v10; // edi
  float *v11; // ecx
  int v12; // ecx
  float v13; // [esp+8h] [ebp-4h]

  v2 = *this;
  if ( *this > 0 )
  {
    v13 = *(float *)(this[2] + 12);
    if ( v13 > 0.0 )
    {
      v3 = 0;
      if ( v2 >= 4 )
      {
        v4 = 0;
        v5 = ((unsigned int)(v2 - 4) >> 2) + 1;
        v3 = 4 * v5;
        do
        {
          *(float *)(this[2] + v4 + 12) = *(float *)(this[2] + v4 + 12) - v13;
          *(float *)(this[2] + v4 + 28) = *(float *)(this[2] + v4 + 28) - v13;
          *(float *)(this[2] + v4 + 44) = *(float *)(this[2] + v4 + 44) - v13;
          v6 = this[2];
          v7 = *(float *)(v6 + v4 + 60);
          v8 = (float *)(v6 + v4 + 60);
          v4 += 64;
          --v5;
          *v8 = v7 - v13;
        }
        while ( v5 );
      }
      if ( v3 < v2 )
      {
        v9 = 16 * v3;
        v10 = v2 - v3;
        do
        {
          v11 = (float *)(this[2] + v9 + 12);
          v9 += 16;
          --v10;
          *v11 = *v11 - v13;
        }
        while ( v10 );
      }
    }
  }
  v12 = this[3];
  if ( v12 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v12 + 8))(v12);
  *((_BYTE *)this + 30) = 1;
}
