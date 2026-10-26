int __cdecl _except_handler3(int a1, _DWORD *TargetFrame, int a3)
{
  int *v3; // ebp
  _DWORD *v4; // ebx
  int v5; // esi
  int v6; // edi
  int (__fastcall *v7)(_DWORD, _DWORD); // eax
  int v8; // eax
  int v9; // edi
  int v10; // ecx
  _DWORD v12[2]; // [esp+10h] [ebp-8h] BYREF
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  v3 = &savedregs;
  v4 = TargetFrame;
  if ( (*(_DWORD *)(a1 + 4) & 6) != 0 )
  {
    _local_unwind2((int)TargetFrame, -1);
    return 1;
  }
  else
  {
    v12[0] = a1;
    v12[1] = a3;
    *(TargetFrame - 1) = v12;
    v5 = TargetFrame[3];
    v6 = TargetFrame[2];
    if ( _ValidateEH3RN(TargetFrame) )
    {
      while ( v5 != -1 )
      {
        v7 = *(int (__fastcall **)(_DWORD, _DWORD))(v6 + 12 * v5 + 4);
        if ( v7 )
        {
          v8 = v7(0, 0);
          v4 = (_DWORD *)v3[3];
          if ( v8 )
          {
            if ( v8 < 0 )
              return 0;
            v9 = v4[2];
            _global_unwind2((PVOID)v3[3]);
            v3 = v4 + 4;
            _local_unwind2((int)v4, v5);
            _NLG_Notify(*(_DWORD *)(v9 + 12 * v5 + 8), (int)(v4 + 4), 1);
            v4[3] = *(_DWORD *)(v9 + 4 * v10);
            v4 = 0;
            v5 = 0;
            (*(void (__fastcall **)(_DWORD, _DWORD))(v9 + 4 * v10 + 8))(0, 0);
          }
        }
        v6 = v4[2];
        v5 = *(_DWORD *)(v6 + 12 * v5);
      }
    }
    else
    {
      *(_DWORD *)(a1 + 4) |= 8u;
    }
    return 1;
  }
}
