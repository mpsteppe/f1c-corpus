int __thiscall sub_585870(int this, int a2, char a3)
{
  _DWORD *v4; // edi
  void *v5; // eax
  int v6; // ebp
  char v7; // bl
  DWORD v8; // eax
  int v9; // eax
  int v10; // edx
  int v11; // ebx
  int v12; // ebp
  int v13; // edi
  int v14; // eax
  _DWORD *v15; // edx
  int v16; // ebx
  _DWORD *v17; // eax
  int v18; // edi
  void *v19; // eax
  _DWORD *v20; // esi
  char v22; // [esp+21h] [ebp-345h]
  int v23; // [esp+22h] [ebp-344h] BYREF
  _DWORD *v24; // [esp+26h] [ebp-340h]
  _DWORD *v25; // [esp+2Ah] [ebp-33Ch]
  _DWORD *v26; // [esp+2Eh] [ebp-338h]
  int v27; // [esp+32h] [ebp-334h]
  int v28; // [esp+36h] [ebp-330h]
  int v29; // [esp+3Ah] [ebp-32Ch]
  _BYTE v30[28]; // [esp+3Eh] [ebp-328h] BYREF
  _BYTE v31[768]; // [esp+5Ah] [ebp-30Ch] BYREF
  int v32; // [esp+362h] [ebp-4h]

  sub_585D20(this);
  v4 = 0;
  v29 = sub_585770((int *)this);
  sub_587030(-1, 255, 0);
  v5 = *(void **)(this + 1600);
  v6 = this + 1572;
  v7 = 0;
  v32 = 0;
  v22 = 0;
  v28 = this + 1572;
  if ( v5 && ((v8 = WaitForSingleObject(v5, *(_DWORD *)(this + 1604))) == 0 || v8 == 128) )
    v9 = this + 1572;
  else
    v9 = 0;
  if ( a3 || *(_BYTE *)(v9 + 25) )
  {
    sub_587370(v9);
    v7 = 1;
  }
  if ( *(_DWORD *)(this + 1600) )
    ReleaseMutex(*(HANDLE *)(this + 1600));
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v10 = *(_DWORD *)this;
  LOBYTE(v32) = 1;
  (*(void (__thiscall **)(int))(v10 + 200))(this);
  if ( v7 )
    v22 = (*(int (__thiscall **)(int, int, _BYTE *, int))(*(_DWORD *)this + 180))(this, v29, v30, 1);
  v11 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 164))(this);
  LOBYTE(v23) = 0;
  if ( v11 > 0 )
  {
    v12 = v23;
    do
    {
      v13 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 28))(this);
      if ( (*(unsigned __int8 (__thiscall **)(int, int, int))(*(_DWORD *)this + 172))(this, v12, v13)
        && (a3 || *(_BYTE *)(v13 + 25))
        && a2 != v29
        && v13 )
      {
        v14 = sub_587C03(12);
        if ( v14 )
        {
          *(_DWORD *)v14 = v13;
          *(_DWORD *)(v14 + 4) = 0;
          *(_BYTE *)(v14 + 8) = 0;
        }
        else
        {
          v14 = 0;
        }
        if ( v24 )
        {
          v15 = v25;
          v25 = (_DWORD *)v14;
          v15[1] = v14;
        }
        else
        {
          v24 = (_DWORD *)v14;
          v26 = (_DWORD *)v14;
          v25 = (_DWORD *)v14;
        }
        ++v27;
      }
      else
      {
        (*(void (__thiscall **)(int, int))(*(_DWORD *)this + 32))(this, v13);
      }
      LOBYTE(v23) = v23 + 1;
      v12 = v23;
    }
    while ( (unsigned __int8)v23 < v11 );
    v4 = v24;
    v6 = v28;
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)this + 204))(this);
  v31[0] = 0;
  LOBYTE(v32) = 2;
  v26 = v4;
  if ( v4 )
  {
    v16 = *v4;
    if ( *v4 )
    {
      while ( 1 )
      {
        v17 = 0;
        while ( *v4 != v16 )
        {
          v17 = v4;
          v4 = (_DWORD *)v4[1];
          if ( !v4 )
            goto LABEL_46;
        }
        if ( v4 == v24 )
          v26 = (_DWORD *)v4[1];
        if ( v17 )
          v17[1] = v4[1];
        else
          v24 = (_DWORD *)v4[1];
        if ( v25 == v4 )
          v25 = v17;
        --v27;
        sub_586620(v4);
        sub_587BCF(v4);
LABEL_46:
        v23 = sub_587250(v16);
        if ( (unsigned __int8)sub_587260(v31, &v23) )
        {
          v18 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 88))(this);
          sub_586800(0, 8, 1, 2, -1);
          (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(v18 + 72) + 12))(*(_DWORD *)(v18 + 72), a2);
          sub_586A00(v31, v23);
          sub_585380((_DWORD *)this, v18);
        }
        (*(void (__thiscall **)(int, int))(*(_DWORD *)this + 32))(this, v16);
        v26 = v24;
        if ( !v24 )
          break;
        v16 = *v24;
        if ( !*v24 )
          break;
        v4 = v24;
      }
      v4 = v24;
      v6 = v28;
    }
  }
  if ( v22 )
  {
    v19 = *(void **)(v6 + 28);
    if ( v19 )
      WaitForSingleObject(v19, *(_DWORD *)(v6 + 32));
    sub_587230(0);
    if ( *(_DWORD *)(v6 + 28) )
      ReleaseMutex(*(HANDLE *)(v6 + 28));
  }
  LOBYTE(v32) = 0;
  if ( v24 )
  {
    do
    {
      v20 = v4;
      v4 = (_DWORD *)v4[1];
      if ( *((_BYTE *)v20 + 8) && *v20 )
        (**(void (__thiscall ***)(_DWORD, int))*v20)(*v20, 1);
      sub_587BCF(v20);
    }
    while ( v4 );
  }
  v32 = -1;
  return sub_5870D0(v30);
}
