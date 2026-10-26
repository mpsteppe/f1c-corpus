LONG __cdecl _XcptFilter(int a1, struct _EXCEPTION_POINTERS *ExceptionInfo)
{
  DWORD *v2; // esi
  int *v3; // edx
  int *v4; // ecx
  void (__cdecl *v5)(int); // ebx
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // ecx
  DWORD v11; // edi
  DWORD v12; // [esp+Ch] [ebp-4h]

  v2 = _getptd();
  v3 = (int *)v2[21];
  v4 = v3;
  do
  {
    if ( *v4 == a1 )
      break;
    v4 += 3;
  }
  while ( v4 < &v3[3 * dword_91369C] );
  if ( v4 >= &v3[3 * dword_91369C] || *v4 != a1 )
    v4 = 0;
  if ( !v4 )
    return UnhandledExceptionFilter(ExceptionInfo);
  v5 = (void (__cdecl *)(int))v4[2];
  if ( !v5 )
    return UnhandledExceptionFilter(ExceptionInfo);
  if ( v5 == (void (__cdecl *)(int))5 )
  {
    v4[2] = 0;
    return 1;
  }
  else
  {
    if ( v5 != (void (__cdecl *)(int))1 )
    {
      v12 = v2[22];
      v2[22] = (DWORD)ExceptionInfo;
      v7 = v4[1];
      if ( v7 == 8 )
      {
        v8 = dword_913690;
        if ( dword_913690 < dword_913690 + dword_913694 )
        {
          v9 = 12 * dword_913690;
          do
          {
            *(_DWORD *)(v9 + v2[21] + 8) = 0;
            ++v8;
            v9 += 12;
          }
          while ( v8 < dword_913690 + dword_913694 );
        }
        v10 = *v4;
        v11 = v2[23];
        switch ( v10 )
        {
          case -1073741682:
            v2[23] = 131;
            break;
          case -1073741680:
            v2[23] = 129;
            break;
          case -1073741679:
            v2[23] = 132;
            break;
          case -1073741677:
            v2[23] = 133;
            break;
          case -1073741683:
            v2[23] = 130;
            break;
          case -1073741681:
            v2[23] = 134;
            break;
          case -1073741678:
            v2[23] = 138;
            break;
        }
        v5(8);
        v2[23] = v11;
      }
      else
      {
        v4[2] = 0;
        v5(v7);
      }
      v2[22] = v12;
    }
    return -1;
  }
}
