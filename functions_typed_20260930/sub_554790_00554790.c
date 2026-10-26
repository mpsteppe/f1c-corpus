void __thiscall sub_554790(int *this, int a2, int a3, int a4)
{
  int v4; // ebx
  int v6; // ecx
  int v7; // esi
  int v8; // eax
  bool v9; // zf
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int i; // edi
  int v14; // eax
  _DWORD v16[64]; // [esp+10h] [ebp-200h]
  _DWORD v17[64]; // [esp+110h] [ebp-100h]

  v4 = a2;
  v6 = this[1117];
  v7 = 0;
  if ( v6 == a2 )
  {
    v11 = a3;
    goto LABEL_50;
  }
  if ( (a2 & 4) != (v6 & 4) )
  {
    v17[0] = 22;
    if ( (a2 & 4) != 0 )
      v16[0] = 1;
    else
      v16[0] = this[1257];
    v7 = 1;
  }
  if ( (a2 & 0x400) != (v6 & 0x400) )
  {
    v17[v7] = 29;
    v16[v7++] = (a2 & 0x400) != 0;
  }
  v8 = a2 & 0x800;
  if ( v8 != (v6 & 0x800) )
  {
    v9 = v8 == 0;
    v10 = this[1263];
    v17[v7] = 27;
    if ( !v9 )
    {
      v11 = a3;
      v16[v7++] = 1;
      if ( a3 != v10 )
      {
        if ( (_WORD)a3 != (_WORD)v10 )
        {
          v17[v7++] = 19;
          v16[v7 - 1] = (unsigned __int16)a3;
        }
        if ( HIWORD(a3) != *((_WORD *)this + 2527) )
        {
          v17[v7] = 20;
          v16[v7++] = HIWORD(a3);
        }
        this[1263] = a3;
      }
      goto LABEL_27;
    }
    v16[v7] = 0;
    v11 = 65538;
    ++v7;
    if ( v10 != 65538 )
    {
      if ( *((_WORD *)this + 2526) != 2 )
      {
        v17[v7] = 19;
        v16[v7++] = 2;
      }
      if ( *((_WORD *)this + 2527) != 1 )
      {
        v17[v7] = 20;
        v16[v7++] = 1;
      }
      this[1263] = 65538;
      HIWORD(a3) = 1;
      goto LABEL_27;
    }
  }
  v11 = a3;
LABEL_27:
  if ( (a2 & 0x1000) != (v6 & 0x1000) && (a2 & 0x1000) != 0 )
  {
    v17[v7] = 27;
    v16[v7++] = 1;
    if ( v11 != 131074 )
    {
      if ( *((_WORD *)this + 2526) != 2 )
      {
        v17[v7] = 19;
        v16[v7++] = 2;
      }
      if ( *((_WORD *)this + 2527) != 2 )
      {
        v17[v7] = 20;
        v16[v7++] = 2;
      }
      v11 = 131074;
      this[1263] = 131074;
      HIWORD(a3) = 2;
    }
  }
  if ( (a2 & 0x10) != (v6 & 0x10) && (a2 & 0x10) != 0 )
  {
    v17[v7] = 9;
    v16[v7++] = 1;
  }
  if ( (a2 & 0x20) != (v6 & 0x20) && (a2 & 0x20) != 0 )
  {
    v17[v7] = 9;
    v16[v7++] = 1;
  }
  if ( (a2 & 0x100) != (v6 & 0x100) && (a2 & 0x100) != 0 )
  {
    v17[v7] = 9;
    v16[v7++] = 2;
  }
  if ( (a2 & 1) != (v6 & 1) )
  {
    v17[v7] = 15;
    v16[v7++] = (a2 & 1) != 0;
  }
  v4 = a2;
LABEL_50:
  if ( (v4 & 0x800) != 0 )
  {
    v12 = this[1263];
    if ( v11 != v12 )
    {
      if ( (_WORD)v11 != (_WORD)v12 )
      {
        v17[v7++] = 19;
        v16[v7 - 1] = (unsigned __int16)v11;
      }
      if ( HIWORD(a3) != *((_WORD *)this + 2527) )
      {
        v17[v7] = 20;
        v16[v7++] = HIWORD(a3);
      }
      this[1263] = v11;
    }
  }
  if ( (v4 & 1) != 0 && a4 != this[1264] )
  {
    v17[v7] = 24;
    v16[v7++] = a4;
    this[1264] = a4;
  }
  if ( v7 > 0 )
  {
    for ( i = 0; i < v7; ++i )
    {
      v14 = (*(int (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)this[1088] + 200))(this[1088], v17[i], v16[i]);
      *this = v14;
    }
  }
  this[1117] = v4;
}

