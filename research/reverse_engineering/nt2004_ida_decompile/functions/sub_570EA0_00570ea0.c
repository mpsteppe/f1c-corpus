char __thiscall sub_570EA0(int *this, int a2)
{
  int v3; // eax
  unsigned int v4; // esi
  void *v5; // eax
  int *v6; // ebp
  DWORD v7; // eax
  int *v8; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int *v12; // eax
  int v13; // eax
  _DWORD *v14; // esi
  _DWORD *v15; // eax
  int *v16; // eax
  bool v17; // zf
  int v18; // esi
  int v19; // eax
  _DWORD *v20; // eax
  unsigned int v21; // esi
  char v23; // [esp+18h] [ebp-32h]
  char v24; // [esp+19h] [ebp-31h]
  char v25; // [esp+1Ah] [ebp-30h]
  _DWORD v26[8]; // [esp+1Eh] [ebp-2Ch] BYREF
  int v27; // [esp+46h] [ebp-4h]

  v24 = 0;
  v23 = 0;
  sub_56B370(v26, 0, 0, 0);
  v3 = *this;
  v27 = 0;
  if ( (*(unsigned __int8 (__thiscall **)(int *, int, _DWORD *))(v3 + 208))(this, a2, v26) )
  {
    v4 = (*(int (__thiscall **)(int *))(*this + 88))(this);
    sub_576880(0, 7, 1, 2, -1);
    (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(v4 + 72) + 12))(*(_DWORD *)(v4 + 72), a2);
    sub_56D580(this, v4, 0);
    (*(void (__thiscall **)(int *, unsigned int))(*this + 92))(this, v4);
    v5 = (void *)this[694];
    v6 = this + 690;
    if ( !v5 || (v7 = WaitForSingleObject(v5, this[695])) != 0 && v7 != 128 )
      v6 = 0;
    v8 = (int *)*v6;
    v6[2] = *v6;
    if ( v8 )
    {
      v9 = *v8;
      if ( *v8 )
      {
        while ( 1 )
        {
          v10 = sub_577280(v9);
          if ( v10 == a2 )
            break;
          v11 = v6[2];
          if ( v11 )
          {
            v12 = *(int **)(v11 + 4);
            v6[2] = (int)v12;
            if ( v12 )
            {
              v9 = *v12;
              if ( *v12 )
                continue;
            }
          }
          goto LABEL_33;
        }
        if ( sub_5772B0(v9) == 2 )
          v23 = 1;
        v13 = *(_DWORD *)(v9 + 28);
        if ( v13 )
        {
          *(_BYTE *)(v13 + 40) = 1;
          sub_56B2B0(*(_DWORD **)(v9 + 28), 0);
        }
        v14 = (_DWORD *)*v6;
        v15 = 0;
        if ( *v6 )
        {
          while ( *v14 != v9 )
          {
            v15 = v14;
            v14 = (_DWORD *)v14[1];
            if ( !v14 )
              goto LABEL_32;
          }
          if ( v14 == (_DWORD *)v6[2] )
            v6[2] = v14[1];
          if ( v15 )
            v15[1] = v14[1];
          else
            *v6 = v14[1];
          if ( (_DWORD *)v6[1] == v14 )
            v6[1] = (int)v15;
          --v6[3];
          if ( *((_BYTE *)v14 + 8) && *v14 )
            (**(void (__thiscall ***)(_DWORD, int))*v14)(*v14, 1);
          sub_5BE8AE();
        }
LABEL_32:
        v24 = 1;
      }
    }
LABEL_33:
    v16 = (int *)*v6;
    v17 = *v6 == 0;
    v6[2] = *v6;
    if ( v17 )
      v18 = 0;
    else
      v18 = *v16;
    v25 = 0;
    if ( v18 )
    {
      do
      {
        sub_577290(v25);
        sub_5772C0(1);
        v19 = v6[2];
        ++v25;
        if ( !v19 )
          break;
        v20 = *(_DWORD **)(v19 + 4);
        v6[2] = (int)v20;
        if ( !v20 )
          break;
      }
      while ( *v20 );
    }
    if ( this[694] )
      ReleaseMutex((HANDLE)this[694]);
    if ( sub_575D90(this) == 4 )
    {
      v21 = (*(int (__thiscall **)(int *))(*this + 88))(this);
      sub_576880(0, 9, 1, 2, -1);
      sub_576A80(&a2, 4);
      *(_BYTE *)(*(_DWORD *)(v21 + 72) + 4) = 1;
      sub_56D580(this, v21, 0);
      (*(void (__thiscall **)(int *, unsigned int))(*this + 92))(this, v21);
    }
    if ( v23 && sub_575D90(this) == 3 )
      (*(void (__thiscall **)(int *))(*this + 116))(this);
  }
  v27 = -1;
  sub_56B3E0(v26);
  return v24;
}
