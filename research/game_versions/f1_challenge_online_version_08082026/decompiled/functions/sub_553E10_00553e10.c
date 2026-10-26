int __thiscall sub_553E10(_DWORD *this, int a2)
{
  _DWORD *v3; // ebx
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  int v9; // edx
  int v10; // edx
  int v11; // edx
  int v12; // edx
  int v13; // edx
  int v14; // edx

  v3 = this + 1;
  *this = a2;
  v4 = this + 6;
  this[10] = 0;
  if ( this != (_DWORD *)-24 && *v4 != 1 )
    *v4 = 1;
  v5 = this + 7;
  if ( this != (_DWORD *)-28 && *v5 != 2 )
    *v5 = 2;
  v6 = this + 8;
  if ( this != (_DWORD *)-32 && *v6 != 1 )
    *v6 = 1;
  (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 4, 1);
  (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 5, 2);
  (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 6, 1);
  this[9] = 0;
  if ( v3 && *v3 != 1 )
    *v3 = 1;
  v7 = v3 + 1;
  if ( v3 != (_DWORD *)-4 && *v7 != 2 )
    *v7 = 2;
  v8 = v3 + 2;
  if ( v3 != (_DWORD *)-8 && *v8 != 1 )
    *v8 = 1;
  (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 1, 1);
  (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 2, 2);
  (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 3, 1);
  v9 = *this;
  this[11] = 0;
  (*(void (__stdcall **)(int, int, int, _DWORD))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, v9, 11, 0);
  v10 = *this;
  this[13] = 0;
  (*(void (__stdcall **)(int, int, int, _DWORD))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, v10, 18, 0);
  v11 = *this;
  this[12] = 0;
  (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)dword_8B89A0 + 244))(dword_8B89A0, v11, 0);
  v12 = *this;
  this[14] = 0;
  (*(void (__stdcall **)(int, int, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, v12, 13, 1);
  v13 = *this;
  this[15] = 0;
  (*(void (__stdcall **)(int, int, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, v13, 14, 1);
  v14 = *this;
  this[16] = 0;
  return (*(int (__stdcall **)(int, int, int, _DWORD))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, v14, 19, 0);
}
