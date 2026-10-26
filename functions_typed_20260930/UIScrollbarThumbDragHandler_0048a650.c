int __thiscall sub_48A650(int *this)
{
  int v2; // eax
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  _DWORD *v9; // edi
  char *v10; // ecx
  char *v11; // eax
  char *v12; // eax
  char *v13; // ebp
  char *v14; // edx
  char *v15; // ecx
  char *v16; // eax
  int v18; // [esp+8h] [ebp-8h] BYREF
  int v19; // [esp+Ch] [ebp-4h] BYREF

  DualFieldRead(&v19, &v18);
  (*(void (__thiscall **)(int *, int))(*this + 44))(this, 1);
  v2 = *this;
  *((_BYTE *)this + 324) = 0;
  *((_BYTE *)this + 325) = 0;
  *((_BYTE *)this + 326) = 0;
  if ( (*(int (__thiscall **)(int *))(v2 + 32))(this) <= 0 )
    v3 = (*(int (__thiscall **)(int *))(*this + 32))(this);
  else
    v3 = this[4];
  v4 = (*(int (__thiscall **)(int *))(*this + 24))(this);
  if ( v19 > v4 && v19 <= v3 )
  {
    v5 = (*(int (__thiscall **)(int *))(*this + 28))(this);
    if ( v18 >= v5 )
    {
      v6 = (*(int (__thiscall **)(int *))(*this + 36))(this);
      if ( v18 >= v6 )
      {
        *((_BYTE *)this + 325) = 1;
        UINavigationAdvanceHandler(this);
      }
      else if ( this[87] )
      {
        v7 = this[84] + (*(int (__thiscall **)(int *))(*this + 28))(this);
        if ( v18 < v7 )
        {
          StateUpdateWithDecrement(this);
          FloatToIntConversion(this);
        }
        else if ( v18 > v7 + this[87] )
        {
          sub_4895B0(this);
          FloatToIntConversion(this);
        }
        else
        {
          *((_BYTE *)this + 326) = 1;
        }
      }
    }
    else
    {
      *((_BYTE *)this + 324) = 1;
      DecrementCounterVirtualCall(this);
    }
    goto LABEL_38;
  }
  if ( !*((_BYTE *)this + 224) || !this[86] )
    goto LABEL_38;
  v8 = sub_489F40(this, v18, 1);
  v9 = (_DWORD *)this[36];
  this[90] = v8;
  if ( v8 <= 0 )
  {
LABEL_21:
    if ( v9 )
    {
      v10 = (char *)v9[44];
      if ( !v10 )
        v10 = byte_5EA438;
      v11 = (char *)this[40];
      if ( !v11 )
        v11 = byte_5EA438;
      StringReverseCopyLookup(v11, v10);
      v12 = (char *)v9[42];
      if ( !v12 )
        v12 = byte_5EA438;
      v13 = (char *)v9[40];
      if ( !v13 )
        v13 = byte_5EA438;
      v14 = (char *)v9[46];
      if ( !v14 )
        v14 = byte_5EA438;
      v15 = (char *)v9[44];
      if ( !v15 )
        v15 = byte_5EA438;
      (*(void (__thiscall **)(int *, char *, char *, char *, char *))(*this + 168))(this, v15, v14, v13, v12);
      goto LABEL_38;
    }
  }
  else
  {
    while ( v9 )
    {
      v9 = (_DWORD *)v9[35];
      if ( --v8 <= 0 )
        goto LABEL_21;
    }
  }
  v16 = (char *)this[40];
  if ( !v16 )
    v16 = byte_5EA438;
  StringReverseCopyLookup(v16, byte_5EA438);
LABEL_38:
  if ( *((_BYTE *)this + 324) )
  {
    (*(void (__thiscall **)(int *, int))(*this + 64))(this, 1);
  }
  else
  {
    if ( *((_BYTE *)this + 325) )
    {
      (*(void (__thiscall **)(int *, int))(*this + 64))(this, 2);
      return (*(int (__thiscall **)(int *))(*this + 152))(this);
    }
    (*(void (__thiscall **)(int *, _DWORD))(*this + 64))(this, 0);
  }
  return (*(int (__thiscall **)(int *))(*this + 152))(this);
}

