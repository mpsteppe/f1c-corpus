void __userpurge sub_4EE325(char a1@<al>, int a2@<ecx>, int a3, int a4)
{
  double v6; // st6
  int v7; // edi
  int v8; // eax
  int v9; // eax
  bool v10; // zf
  signed int v11; // eax
  _DWORD v12[3]; // [esp+4h] [ebp-18h] BYREF
  _DWORD v13[3]; // [esp+10h] [ebp-Ch] BYREF
  int v14; // [esp+20h] [ebp+4h]

  if ( !a1 )
  {
    v6 = a3 >= 81 ? *(float *)&dword_B70948 : flt_B70A44;
    if ( v6 != 0.0
      && *(_DWORD *)dword_B72314 != 7
      && *(_DWORD *)dword_B72314 != 8
      && (!a4 || !*(_DWORD *)(a4 + 14820))
      && (*(_DWORD *)(a2 + 424) == 2139095039 || a3 == 67) )
    {
      if ( a3 >= 81 )
      {
        v9 = *(_DWORD *)(a2 + 4 * a3);
        if ( !v9 || (*(int (**)(void))(*(_DWORD *)v9 + 28))() == 2 )
        {
LABEL_20:
          if ( (unsigned int)a3 <= 0x5C )
          {
            if ( a3 != 42 && a3 != 43 && a3 != 44 )
              goto LABEL_38;
            if ( (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 140) + 28))(*(_DWORD *)(a2 + 140)) == 2
              && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 168) + 28))(*(_DWORD *)(a2 + 168)) == 2
              && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 172) + 28))(*(_DWORD *)(a2 + 172)) == 2
              && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 176) + 28))(*(_DWORD *)(a2 + 176)) == 2 )
            {
              v11 = rand() & 0x80000001;
              v10 = v11 == 0;
              if ( v11 < 0 )
                v10 = (((_BYTE)v11 - 1) | 0xFFFFFFFE) == -1;
              if ( v10 )
              {
LABEL_38:
                if ( *(_DWORD *)(a2 + 4 * a3) )
                {
                  memset(v13, 0, sizeof(v13));
                  memset(v12, 0, sizeof(v12));
                  if ( a3 >= 81 )
                    v14 = dword_B70948;
                  else
                    v14 = LODWORD(flt_B70A44);
                  (*(void (__thiscall **)(_DWORD, int, _DWORD *, _DWORD *, int, int, _DWORD))(**(_DWORD **)(a2 + 4 * a3)
                                                                                            + 4))(
                    *(_DWORD *)(a2 + 4 * a3),
                    2,
                    v13,
                    v12,
                    v14,
                    1065353216,
                    0);
                }
              }
            }
          }
        }
      }
      else
      {
        v7 = 0;
        while ( 1 )
        {
          v8 = *(_DWORD *)(a2 + 4 * v7);
          if ( v8 )
          {
            if ( (*(int (**)(void))(*(_DWORD *)v8 + 28))() != 2 )
              break;
          }
          if ( ++v7 >= 81 )
            goto LABEL_20;
        }
      }
    }
  }
}
