// f1c  0x00592924  size=318
LONG __cdecl sub_592924(int a1, struct _EXCEPTION_POINTERS *ExceptionInfo)
{
  _DWORD *v2; // esi
  int *v3; // eax
  void (__cdecl *v4)(int); // ebx
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  int v9; // eax
  int v10; // edi
  int v11; // [esp+8h] [ebp-4h]

  v2 = sub_58E0C7();
  v3 = (int *)sub_592A62(a1, v2[20]);
  if ( !v3 )
    return UnhandledExceptionFilter(ExceptionInfo);
  v4 = (void (__cdecl *)(int))v3[2];
  if ( !v4 )
    return UnhandledExceptionFilter(ExceptionInfo);
  if ( v4 == (void (__cdecl *)(int))5 )
  {
    v3[2] = 0;
    return 1;
  }
  else
  {
    if ( v4 != (void (__cdecl *)(int))1 )
    {
      v11 = v2[21];
      v2[21] = ExceptionInfo;
      v6 = v3[1];
      if ( v6 == 8 )
      {
        v7 = dword_5E7888;
        if ( dword_5E7888 < dword_5E7888 + dword_5E788C )
        {
          v8 = 12 * dword_5E7888;
          do
          {
            v8 += 12;
            *(_DWORD *)(v8 + v2[20] - 4) = 0;
            ++v7;
          }
          while ( v7 < dword_5E7888 + dword_5E788C );
        }
        v9 = *v3;
        v10 = v2[22];
        switch ( v9 )
        {
          case -1073741682:
            v2[22] = 131;
            break;
          case -1073741680:
            v2[22] = 129;
            break;
          case -1073741679:
            v2[22] = 132;
            break;
          case -1073741677:
            v2[22] = 133;
            break;
          case -1073741683:
            v2[22] = 130;
            break;
          case -1073741681:
            v2[22] = 134;
            break;
          case -1073741678:
            v2[22] = 138;
            break;
        }
        v4(8);
        v2[22] = v10;
      }
      else
      {
        v3[2] = 0;
        v4(v6);
      }
      v2[21] = v11;
    }
    return -1;
  }
}
