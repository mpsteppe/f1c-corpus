int *__thiscall sub_40F050(int this)
{
  __int16 v2; // bx
  __int16 **v3; // eax
  __int16 *v4; // eax
  __int16 v5; // di
  void *v6; // eax
  int v7; // edi
  int *v8; // eax
  int v9; // ecx
  _DWORD *v10; // eax
  int v11; // eax
  unsigned __int8 v12; // bl
  int v13; // edi
  int v14; // eax
  const char *v15; // eax
  int v16; // edi
  int v17; // edi
  int v18; // eax
  const char *v19; // eax
  _DWORD *v20; // eax
  int *result; // eax
  int v22; // ebp
  int v23; // eax
  char *v24; // [esp-4h] [ebp-30h]
  int v25; // [esp+10h] [ebp-1Ch]
  int v26; // [esp+14h] [ebp-18h]
  char v27; // [esp+1Ch] [ebp-10h]
  char v28; // [esp+20h] [ebp-Ch]
  int v29; // [esp+24h] [ebp-8h]
  char v30; // [esp+28h] [ebp-4h]
  int v31; // [esp+28h] [ebp-4h]

  if ( !(*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 36))(dword_76BB24) )
  {
    v30 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 52))(dword_76BB24);
    v2 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 68))(dword_76BB24);
    if ( *(int *)(this + 24) <= 0
      || (v3 = *(__int16 ***)(this + 12)) == 0
      || (v4 = *v3) == 0
      || (v5 = *v4, v5 != (*(unsigned __int16 (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 68))(dword_76BB24)) )
    {
      v6 = operator new(0x1Cu);
      v7 = v6 ? sub_413DB0(v6) : 0;
      if ( v7 )
      {
        v8 = (int *)operator new(0xCu);
        if ( v8 )
        {
          *v8 = v7;
          v8[1] = 0;
          *((_BYTE *)v8 + 8) = 1;
        }
        else
        {
          v8 = 0;
        }
        v9 = *(_DWORD *)(this + 12);
        if ( v9 )
        {
          v8[1] = v9;
        }
        else
        {
          *(_DWORD *)(this + 16) = v8;
          *(_DWORD *)(this + 20) = v8;
        }
        *(_DWORD *)(this + 12) = v8;
        ++*(_DWORD *)(this + 24);
      }
    }
    if ( *(int *)(this + 24) > 0 )
    {
      v10 = *(_DWORD **)(this + 12);
      if ( v10 )
      {
        if ( *v10 )
          sub_413E60(v2, v30);
      }
    }
  }
  v27 = 43;
  v28 = 43;
  v25 = 0;
  v26 = 0;
  v31 = 0;
  v29 = 0;
  v11 = sub_40EBD0((const char **)this);
  if ( v11 )
  {
    v12 = *(_BYTE *)(v11 + 20884);
    LOWORD(v31) = *(_WORD *)(v11 + 20848);
    v27 = *(_BYTE *)(v11 + 20876);
    v28 = v12;
    v13 = sub_4DEBD0(v11 + 20836);
    v29 = v13;
    if ( sub_57AE50(aSeasonscoringi) )
    {
      v14 = sub_57A700(v12 - 1);
      if ( v14 )
      {
        v15 = (const char *)sub_57A6D0(v14);
        v25 = atoi(v15);
      }
    }
    if ( v13 )
      v25 += 5;
    v16 = *(_DWORD *)dword_76BB24;
    v24 = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 36))(dword_76BB24);
    v17 = (*(int (__thiscall **)(int))(v16 + 64))(dword_76BB24);
    (**(void (__thiscall ***)(int, char *))dword_76BB24)(dword_76BB24, aRacepursemulti);
    if ( sub_57AE50(v24) )
    {
      v18 = sub_57A700(v12 - 1);
      if ( v18 )
      {
        v19 = (const char *)sub_57A6D0(v18);
        v26 = (__int64)(atof(v19) * (double)v17 + 0.5);
      }
    }
  }
  if ( *(int *)(this + 24) > 0 )
  {
    v20 = *(_DWORD **)(this + 12);
    if ( v20 )
    {
      if ( *v20 )
        sub_413E00(v27, v28, v25, v26, v29);
    }
  }
  result = *(int **)(this + 28);
  if ( result )
  {
    v22 = *result;
    v23 = sub_40EBD0((const char **)this);
    (*(void (__thiscall **)(_DWORD, int))(v22 + 8))(*(_DWORD *)(this + 28), v23);
    return (int *)(*(int (__thiscall **)(_DWORD, char, char, int, int))(**(_DWORD **)(this + 28) + 4))(
                    *(_DWORD *)(this + 28),
                    v27,
                    v28,
                    v31,
                    v26);
  }
  return result;
}
