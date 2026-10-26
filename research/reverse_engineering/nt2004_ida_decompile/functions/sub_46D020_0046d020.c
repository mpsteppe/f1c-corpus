void __thiscall sub_46D020(_DWORD *this, int a2)
{
  void *v3; // edi
  int v4; // eax
  _DWORD *v5; // esi
  _DWORD *v6; // eax
  _DWORD *v7; // esi
  _DWORD *v8; // eax

  if ( *(_DWORD *)a2 >> 28 == 1 && ((*(_BYTE *)(a2 + 2) & 0x3F) == 0 || (*(_BYTE *)(a2 + 2) & 0x3F) == 7) )
  {
    if ( (*(_DWORD *)a2 & 0x3Fu) < 0x31 )
      sub_46C830(284 * (*(_DWORD *)a2 & 0x3F) + *this + 140, a2);
  }
  else
  {
    v3 = operator new(0xD0u);
    if ( v3 )
    {
      sub_4D1850(a2);
      v4 = (*(_DWORD *)a2 >> 26) & 3;
      if ( v4 == 3 || v4 == 2 || (*(_DWORD *)a2 & 0xF0000000) != 0x10000000 )
      {
        v7 = (_DWORD *)(*this + 108);
        v8 = operator new(0xCu);
        if ( v8 )
        {
          *v8 = v3;
          v8[1] = 0;
          *((_BYTE *)v8 + 8) = 1;
        }
        else
        {
          v8 = 0;
        }
        if ( *v7 )
        {
          *(_DWORD *)(v7[1] + 4) = v8;
        }
        else
        {
          *v7 = v8;
          v7[2] = v8;
        }
        v7[1] = v8;
        ++v7[3];
      }
      else
      {
        v5 = (_DWORD *)(*this + 124);
        v6 = operator new(0xCu);
        if ( v6 )
        {
          *v6 = v3;
          v6[1] = 0;
          *((_BYTE *)v6 + 8) = 1;
        }
        else
        {
          v6 = 0;
        }
        if ( *v5 )
        {
          *(_DWORD *)(v5[1] + 4) = v6;
        }
        else
        {
          *v5 = v6;
          v5[2] = v6;
        }
        v5[1] = v6;
        ++v5[3];
      }
    }
  }
}
