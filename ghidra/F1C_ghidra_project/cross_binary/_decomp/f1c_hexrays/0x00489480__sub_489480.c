// f1c  0x00489480  size=76
void __thiscall sub_489480(_DWORD *this)
{
  int v2; // ecx
  int v3; // eax
  int v4; // eax
  int v5; // edi
  int v6; // ebx
  int v7; // ecx

  v2 = this[92];
  if ( v2 >= 0 )
  {
    v3 = this[37];
    if ( v3 > v2 )
    {
      v4 = v3 - v2;
      v5 = v4;
      if ( v4 > 0 )
      {
        v6 = v4;
        do
        {
          v7 = this[36];
          if ( v7 )
          {
            this[36] = *(_DWORD *)(v7 + 140);
            (**(void (__thiscall ***)(int, int))v7)(v7, 1);
          }
          --v6;
        }
        while ( v6 );
      }
      this[37] -= v5;
    }
  }
}
