int __cdecl sub_597388(_DWORD *a1)
{
  void (__cdecl *v2)(_DWORD); // ebx
  int *v3; // edi
  _DWORD *v4; // esi
  int v5; // ecx
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  int v9; // [esp+Ch] [ebp-Ch]
  int v10; // [esp+10h] [ebp-8h]
  int v11; // [esp+14h] [ebp-4h]

  v11 = 0;
  if ( a1 == (_DWORD *)2 )
  {
    v2 = (void (__cdecl *)(_DWORD))dword_8D41E8;
    v3 = &dword_8D41E8;
  }
  else
  {
    if ( a1 == (_DWORD *)4 || a1 == (_DWORD *)8 || a1 == (_DWORD *)11 )
    {
      v4 = TLSValueRetrievalWithInit();
      v3 = (int *)(ArrayOfStructLinearSearchByID_750a(a1, v4[20]) + 8);
      v2 = (void (__cdecl *)(_DWORD))*v3;
      goto LABEL_15;
    }
    if ( a1 == (_DWORD *)15 )
    {
      v2 = (void (__cdecl *)(_DWORD))dword_8D41F4;
      v3 = &dword_8D41F4;
    }
    else if ( a1 == (_DWORD *)21 )
    {
      v2 = (void (__cdecl *)(_DWORD))dword_8D41EC;
      v3 = &dword_8D41EC;
    }
    else
    {
      if ( a1 != (_DWORD *)22 )
        return -1;
      v2 = (void (__cdecl *)(_DWORD))dword_8D41F0;
      v3 = &dword_8D41F0;
    }
  }
  v11 = 1;
  CriticalSectionLazyInitEnter(1);
  v4 = a1;
LABEL_15:
  if ( v2 != (void (__cdecl *)(_DWORD))1 )
  {
    v5 = 0;
    if ( !v2 )
    {
      if ( v11 )
        CritSectLeave(1);
      sub_589CB5(3u);
    }
    if ( a1 == (_DWORD *)8 || a1 == (_DWORD *)11 || a1 == (_DWORD *)4 )
    {
      v10 = v4[21];
      v4[21] = v5;
      if ( a1 != (_DWORD *)8 )
        goto LABEL_32;
      v6 = v4[22];
      v4[22] = 140;
      v9 = v6;
    }
    if ( a1 == (_DWORD *)8 )
    {
      v7 = dword_5E7888;
      if ( dword_5E7888 < dword_5E7888 + dword_5E788C )
      {
        v8 = 12 * dword_5E7888;
        do
        {
          v8 += 12;
          *(_DWORD *)(v4[20] + v8 - 4) = 0;
          ++v7;
        }
        while ( v7 < dword_5E7888 + dword_5E788C );
      }
LABEL_33:
      if ( v11 )
        CritSectLeave(1);
      if ( a1 == (_DWORD *)8 )
      {
        ((void (__cdecl *)(int, _DWORD))v2)(8, v4[22]);
      }
      else
      {
        v2(a1);
        if ( a1 != (_DWORD *)11 && a1 != (_DWORD *)4 )
          return 0;
      }
      v4[21] = v10;
      if ( a1 == (_DWORD *)8 )
        v4[22] = v9;
      return 0;
    }
LABEL_32:
    *v3 = v5;
    goto LABEL_33;
  }
  if ( v11 )
    CritSectLeave(1);
  return 0;
}

