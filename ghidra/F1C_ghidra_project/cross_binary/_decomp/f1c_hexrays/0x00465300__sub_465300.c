// f1c  0x00465300  size=298
char __thiscall sub_465300(_DWORD *this, _DWORD *a2)
{
  int v3; // eax
  int v4; // edi
  _DWORD *v5; // esi
  int v6; // eax
  int *v7; // esi

  if ( *a2 >> 29 == 1 && ((v3 = (*a2 >> 18) & 0x3F) == 0 || v3 == 7) )
  {
    if ( (unsigned __int8)*a2 < 0x68u )
      LOBYTE(v3) = sub_464B40(560 * (unsigned __int8)*a2 + *this + 140, (int)a2);
  }
  else
  {
    v3 = sub_587C03(432);
    v4 = v3;
    if ( v3 )
    {
      sub_4B3A90(a2);
      if ( (*a2 & 0x8000000) != 0 || (*a2 & 0xE0000000) != 0x20000000 )
      {
        v7 = (int *)(*this + 108);
        v3 = sub_587C03(12);
        if ( v3 )
        {
          *(_DWORD *)v3 = v4;
          *(_DWORD *)(v3 + 4) = 0;
          *(_BYTE *)(v3 + 8) = 1;
        }
        else
        {
          v3 = 0;
        }
        if ( *v7 )
        {
          *(_DWORD *)(v7[1] + 4) = v3;
          v7[1] = v3;
          ++v7[3];
        }
        else
        {
          *v7 = v3;
          v7[2] = v3;
          v7[1] = v3;
          v3 = v7[3] + 1;
          v7[3] = v3;
        }
      }
      else
      {
        v5 = (_DWORD *)(*this + 124);
        v6 = sub_587C03(12);
        if ( v6 )
        {
          *(_DWORD *)v6 = v4;
          *(_DWORD *)(v6 + 4) = 0;
          *(_BYTE *)(v6 + 8) = 1;
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
        v3 = v5[3] + 1;
        v5[3] = v3;
      }
    }
  }
  return v3;
}
