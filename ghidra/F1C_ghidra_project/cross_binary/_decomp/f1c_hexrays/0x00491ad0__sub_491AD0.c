// f1c  0x00491ad0  size=246
__int16 **__thiscall sub_491AD0(_DWORD *this)
{
  _DWORD *v1; // esi
  int v2; // ecx
  int v3; // ebp
  __int16 **v4; // eax
  bool v5; // zf
  __int16 *v6; // eax
  int v7; // edi
  _DWORD *v8; // esi
  int v9; // eax
  int v10; // eax
  __int16 **v11; // eax
  int v14; // [esp+14h] [ebp-8h]
  int v15; // [esp+18h] [ebp-4h]

  v1 = this;
  sub_4910D0(*this + 28);
  v2 = 0;
  v15 = *(_DWORD *)(*v1 + 4);
  v14 = 0;
  do
  {
    if ( v2 == 1 )
      v3 = *v1 + 44;
    else
      v3 = *(_DWORD *)(*v1 + 8) + 16 * v15;
    v4 = *(__int16 ***)v3;
    v5 = *(_DWORD *)v3 == 0;
    *(_DWORD *)(v3 + 8) = *(_DWORD *)v3;
    if ( !v5 )
    {
      v6 = *v4;
      if ( v6 )
      {
        while ( 1 )
        {
          v7 = sub_490940(*v6, v6[1], v6[2], v6[3]);
          v8 = (_DWORD *)(*v1 + 28);
          if ( v7 )
          {
            v9 = sub_587C03(12);
            if ( v9 )
            {
              *(_DWORD *)v9 = v7;
              *(_DWORD *)(v9 + 4) = 0;
              *(_BYTE *)(v9 + 8) = 0;
            }
            else
            {
              v9 = 0;
            }
            if ( *v8 )
            {
              *(_DWORD *)(v8[1] + 4) = v9;
            }
            else
            {
              *v8 = v9;
              v8[2] = v9;
            }
            v8[1] = v9;
            ++v8[3];
          }
          v10 = *(_DWORD *)(v3 + 8);
          if ( !v10 )
            break;
          v11 = *(__int16 ***)(v10 + 4);
          *(_DWORD *)(v3 + 8) = v11;
          if ( !v11 )
            break;
          v6 = *v11;
          if ( !v6 )
            break;
          v1 = this;
        }
        v2 = v14;
        v1 = this;
      }
    }
    v14 = ++v2;
  }
  while ( v2 < 2 );
  return sub_490D00(*v1 + 28, *v1 + 12);
}
