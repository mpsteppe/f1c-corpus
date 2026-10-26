_DWORD *__thiscall sub_67FE1F(int this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  _DWORD *v13; // [esp+Ch] [ebp-4h]

  v2 = (_DWORD *)sub_65B229(64);
  if ( v2 )
  {
    v3 = sub_67F449(v2);
    v13 = v3;
  }
  else
  {
    v13 = 0;
    v3 = 0;
  }
  if ( v3 )
  {
    v3[4] = *(_DWORD *)(this + 16);
    v3[5] = *(_DWORD *)(this + 20);
    v3[6] = *(_DWORD *)(this + 24);
    v3[7] = *(_DWORD *)(this + 28);
    v3[13] = *(_DWORD *)(this + 52);
    if ( !*(_DWORD *)(this + 32)
      || (v4 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 32) + 4))(*(_DWORD *)(this + 32)), (v3[8] = v4) != 0) )
    {
      if ( !*(_DWORD *)(this + 36)
        || (v5 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 36) + 4))(*(_DWORD *)(this + 36)),
            (v3[9] = v5) != 0) )
      {
        if ( !*(_DWORD *)(this + 40)
          || (v6 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 40) + 4))(*(_DWORD *)(this + 40)),
              (v3[10] = v6) != 0) )
        {
          if ( !*(_DWORD *)(this + 44)
            || (v7 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 44) + 4))(*(_DWORD *)(this + 44)),
                (v3[11] = v7) != 0) )
          {
            if ( !*(_DWORD *)(this + 48)
              || (v8 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 48) + 4))(*(_DWORD *)(this + 48)),
                  (v3[12] = v8) != 0) )
            {
              v9 = *(_DWORD *)(this + 52);
              if ( !v9 )
                return v3;
              v10 = sub_67EB7E((_DWORD *)dword_FB9E44, 4 * v9, 0x10u);
              v3[14] = v10;
              if ( v10 )
              {
                v11 = sub_67EB7E((_DWORD *)dword_FB9E44, 4 * *(_DWORD *)(this + 20), 0x10u);
                v3[15] = v11;
                if ( v11 )
                {
                  qmemcpy((void *)v3[14], *(const void **)(this + 56), 4 * *(_DWORD *)(this + 52));
                  qmemcpy((void *)v13[15], *(const void **)(this + 60), 4 * *(_DWORD *)(this + 20));
                  return v13;
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
