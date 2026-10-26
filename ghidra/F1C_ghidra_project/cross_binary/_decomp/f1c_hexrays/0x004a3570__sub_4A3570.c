// f1c  0x004a3570  size=128
void __thiscall sub_4A3570(float *this, float a2)
{
  int v3; // eax
  int v4; // ebx
  int v5; // edi
  int v6; // edi
  int v7; // ebx
  float v8; // [esp+14h] [ebp+4h]

  if ( (*(_BYTE *)this & 1) != 0 )
  {
    v3 = *((_DWORD *)this + 2);
    if ( v3 > 0 )
    {
      *((_DWORD *)this + 2) = v3 - 1;
      v4 = 0;
      if ( *((int *)this + 3) > 0 )
      {
        v5 = 0;
        do
        {
          *(_DWORD *)(*((_DWORD *)this + 4) + v5 + 68) = -1082130432;
          sub_4A2840(v5 + *((_DWORD *)this + 4), 0.0);
          ++v4;
          v5 += 120;
        }
        while ( v4 < *((_DWORD *)this + 3) );
      }
    }
  }
  if ( (*(_BYTE *)this & 2) != 0 )
  {
    v6 = 0;
    v8 = a2 - this[1];
    if ( *((int *)this + 3) > 0 )
    {
      v7 = 0;
      do
      {
        sub_4A2840(v7 + *((_DWORD *)this + 4), v8);
        ++v6;
        v7 += 120;
      }
      while ( v6 < *((_DWORD *)this + 3) );
    }
  }
}
