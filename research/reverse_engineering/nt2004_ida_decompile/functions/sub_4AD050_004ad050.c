int __thiscall sub_4AD050(int this, int a2)
{
  _DWORD *v3; // esi
  int v4; // eax
  int result; // eax
  _DWORD *v6; // eax
  int v7; // ecx
  char *v8; // eax
  int v9; // edx
  double v10; // st7

  v3 = *(_DWORD **)(this + 24);
  if ( v3 )
  {
    if ( !dword_608F60 || dword_608F60 == 3 || dword_608F60 == 5 )
    {
      if ( !*(_BYTE *)(this + 36) )
      {
        while ( 1 )
        {
          v6 = (_DWORD *)sub_4AEF90(v3);
          if ( v6 )
          {
            if ( v6[4] - v6[3] >= 800 && v6[2] - v6[1] >= 600 )
              break;
          }
          if ( !v3[23] )
            break;
          v3 = (_DWORD *)v3[23];
        }
        v7 = *(_DWORD *)(this + 24);
        if ( v7 )
          sub_4AF160(v7);
        for ( ; v3; v3 = (_DWORD *)v3[22] )
          (*(void (__thiscall **)(_DWORD *))(*v3 + 24))(v3);
        sub_4AC390(this);
        sub_4AC400((char *)this);
        sub_4AD1D0(this);
        sub_4ABA40(this);
      }
      if ( *(float *)(this + 64) <= 0.0 )
      {
        if ( (_BYTE)a2 )
          sub_4AD1A0(1);
        *(_BYTE *)(this + 36) = 0;
        return 0;
      }
      else
      {
        v8 = *(char **)(this + 56);
        if ( !v8 )
          v8 = &byte_629120;
        sub_4AEA10(v8, 1);
        v10 = *(float *)(this + 64) - sub_4AE720(this, v9);
        *(_BYTE *)(this + 36) = 0;
        result = 0;
        *(float *)(this + 64) = v10;
      }
    }
    else
    {
      return -1;
    }
  }
  else
  {
    v4 = sub_4AB570();
    sub_4AB0E0(v4, 0, 0, *(_DWORD *)(v4 + 28), *(_DWORD *)(v4 + 32), 656386);
    sub_4AE3F0(0, (int)aNoDrawStackAva, 0, 0, 0);
    sub_4AD1A0(a2);
    return -1;
  }
  return result;
}
