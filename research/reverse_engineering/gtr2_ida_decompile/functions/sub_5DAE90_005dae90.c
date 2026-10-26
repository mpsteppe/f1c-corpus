char __thiscall sub_5DAE90(char *this, char a2, int a3)
{
  int v4; // ecx
  char result; // al
  int v6; // eax
  _DWORD *v7; // eax
  _DWORD **v8; // eax
  _DWORD *i; // eax
  int v10; // eax
  _DWORD **v11; // eax
  int v12; // [esp-8h] [ebp-Ch]

  v4 = *(_DWORD *)this;
  result = 0;
  if ( (v4 & 0x40) != 0 )
  {
    v6 = *((_DWORD *)this + 156);
    *(_DWORD *)this = v4 & 0xFFFFFF3F;
    if ( v6 )
      sub_5D7280(this + 180, (int)(this + 72), (float *)(v6 + 180));
    else
      qmemcpy(this + 184, this + 76, 0x40u);
    if ( (*(_DWORD *)this & 0x20) != 0 )
    {
      v7 = (_DWORD *)*((_DWORD *)this + 155);
      if ( (*v7 & 0x400) != 0 )
      {
        v12 = (int)(this + 320);
        if ( (*(_DWORD *)this & 0x200) != 0 )
          sub_5D8C20(dword_FB27A8, (int)(this + 184), (int)(this + 40), v12);
        else
          sub_5D8C20(dword_FB27A8, (int)(this + 184), (int)(v7 + 72), v12);
      }
    }
    if ( a2 )
    {
      v8 = (_DWORD **)*((_DWORD *)this + 133);
      *((_DWORD *)this + 135) = v8;
      if ( v8 )
      {
        for ( i = *v8; i; i = *v11 )
        {
          *i &= 0xFFFF5FFF;
          v10 = *((_DWORD *)this + 135);
          if ( !v10 )
            break;
          v11 = *(_DWORD ***)(v10 + 4);
          *((_DWORD *)this + 135) = v11;
          if ( !v11 )
            break;
        }
      }
    }
    return 1;
  }
  return result;
}
