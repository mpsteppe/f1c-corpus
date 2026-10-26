int __thiscall sub_4330D0(_DWORD *this, int a2)
{
  int result; // eax
  _DWORD *v4; // eax
  int v5; // eax
  _DWORD *v6; // eax
  _DWORD v7[7]; // [esp+4h] [ebp-31Ch] BYREF
  CHAR v8[256]; // [esp+20h] [ebp-300h] BYREF
  CHAR FileName[512]; // [esp+120h] [ebp-200h] BYREF

  result = PhysicsFilePathBuild(a2, (int)v8, 256);
  if ( !result )
  {
    ZeroInitSmallStruct(v7);
    sub_568620(512);
    ToggleFileReadOnlyAttributeViaWin32API(FileName, 128);
    if ( (unsigned __int8)sub_566940(v8, 0, 1, 1) )
    {
      v4 = (_DWORD *)this[7];
      this[9] = v4;
      if ( v4 && *v4 )
      {
        do
        {
          AutoLoadEntryWriter(v7);
          v5 = this[9];
          if ( !v5 )
            break;
          v6 = *(_DWORD **)(v5 + 4);
          this[9] = v6;
          if ( !v6 )
            break;
        }
        while ( *v6 );
      }
      ConditionalFileHandleCloseWithFlagDispatch(v7);
    }
    return SubCallWithConditionalFieldFree(v7);
  }
  return result;
}

