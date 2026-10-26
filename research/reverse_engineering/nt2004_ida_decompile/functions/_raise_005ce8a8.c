int __cdecl raise(int Signal)
{
  void (__cdecl *v2)(_DWORD); // ebx
  int *v3; // edi
  _DWORD *v4; // esi
  int v5; // edx
  int v6; // ecx
  int v7; // eax
  int v8; // [esp+Ch] [ebp-Ch]
  int v9; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h]

  v10 = 0;
  switch ( Signal )
  {
    case 2:
      v2 = (void (__cdecl *)(_DWORD))dword_7FF498;
      v3 = &dword_7FF498;
      break;
    case 4:
    case 8:
    case 11:
      v4 = _getptd();
      v3 = (int *)(siglookup(Signal, v4[20]) + 8);
      v2 = (void (__cdecl *)(_DWORD))*v3;
      goto LABEL_15;
    case 15:
      v2 = (void (__cdecl *)(_DWORD))dword_7FF4A4;
      v3 = &dword_7FF4A4;
      break;
    case 21:
      v2 = (void (__cdecl *)(_DWORD))dword_7FF49C;
      v3 = &dword_7FF49C;
      break;
    case 22:
      v2 = (void (__cdecl *)(_DWORD))dword_7FF4A0;
      v3 = &dword_7FF4A0;
      break;
    default:
      return -1;
  }
  v10 = 1;
  _lock(1);
  v4 = (_DWORD *)Signal;
LABEL_15:
  if ( v2 != (void (__cdecl *)(_DWORD))1 )
  {
    if ( !v2 )
    {
      if ( v10 )
        _unlock(1);
      _exit(3);
    }
    if ( Signal == 8 || Signal == 11 || Signal == 4 )
    {
      v9 = v4[21];
      v4[21] = 0;
      if ( Signal != 8 )
        goto LABEL_32;
      v5 = v4[22];
      v4[22] = 140;
      v8 = v5;
    }
    if ( Signal == 8 )
    {
      v6 = dword_626550;
      if ( dword_626550 < dword_626550 + dword_626554 )
      {
        v7 = 12 * dword_626550;
        do
        {
          v7 += 12;
          *(_DWORD *)(v4[20] + v7 - 4) = 0;
          ++v6;
        }
        while ( v6 < dword_626550 + dword_626554 );
      }
LABEL_33:
      if ( v10 )
        _unlock(1);
      if ( Signal == 8 )
      {
        ((void (__cdecl *)(int, _DWORD))v2)(8, v4[22]);
      }
      else
      {
        v2(Signal);
        if ( Signal != 11 && Signal != 4 )
          return 0;
      }
      v4[21] = v9;
      if ( Signal == 8 )
        v4[22] = v8;
      return 0;
    }
LABEL_32:
    *v3 = 0;
    goto LABEL_33;
  }
  if ( v10 )
    _unlock(1);
  return 0;
}
