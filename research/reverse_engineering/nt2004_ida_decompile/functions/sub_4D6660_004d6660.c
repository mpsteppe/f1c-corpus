char __thiscall sub_4D6660(_DWORD *this, int a2)
{
  int v2; // esi
  char result; // al
  char *v5; // ebp
  int v6; // eax
  char ***v7; // esi
  char **v8; // eax
  char **v9; // ebp
  int v10; // eax
  int v11; // ebp
  _DWORD *v12; // eax
  bool v13; // zf
  _DWORD *v14; // eax
  void *v15; // ebp
  _DWORD *v16; // eax
  bool v17; // cc
  int *v18; // ebp
  int v19; // esi
  int v20; // eax
  char v21; // al
  int *v22; // eax
  int v23; // ebp
  int v24; // ecx
  float **v25; // eax
  float *v26; // eax
  double v27; // st7
  char *v28; // [esp-Ch] [ebp-12Ch]
  int v29; // [esp-Ch] [ebp-12Ch]
  unsigned __int8 v30; // [esp+Dh] [ebp-113h] BYREF
  unsigned __int8 v31; // [esp+Eh] [ebp-112h] BYREF
  unsigned __int8 v32; // [esp+Fh] [ebp-111h] BYREF
  int v33; // [esp+10h] [ebp-110h]
  _DWORD *i; // [esp+14h] [ebp-10Ch]
  size_t Buffer; // [esp+18h] [ebp-108h] BYREF
  int v36; // [esp+1Ch] [ebp-104h] BYREF
  _BYTE v37[256]; // [esp+20h] [ebp-100h] BYREF

  v2 = a2;
  result = sub_4D7B90(a2);
  if ( result )
  {
    sub_57A3D0(&Buffer, 4u);
    sub_57A3D0(v37, Buffer);
    v37[Buffer] = 0;
    sub_578600(v37);
    sub_57A3D0(&Buffer, 4u);
    sub_57A3D0(v37, Buffer);
    v37[Buffer] = 0;
    sub_578600(v37);
    v31 = 0;
    sub_57A3D0(&v31, 1u);
    this[510] = v31;
    v32 = 0;
    sub_57A3D0(&v32, 1u);
    this[511] = v32;
    sub_4D5710(this);
    sub_57A3D0(&v36, 4u);
    v33 = 0;
    if ( v36 > 0 )
    {
      do
      {
        v5 = 0;
        sub_414470(this + 4);
        v6 = this[6];
        if ( v6 )
        {
          v5 = *(char **)v6;
          v28 = *(char **)v6;
          *(_BYTE *)(v6 + 8) = 0;
          if ( !(unsigned __int8)sub_4DAE20(v28, 1) )
            v5 = 0;
        }
        if ( !v5 )
        {
          sub_4DB880(this);
          v5 = (char *)sub_4DB980(this + 4);
        }
        sub_4D4340(v5, a2);
        v7 = (char ***)&this[4 * (unsigned __int8)*v5 + 16];
        v8 = (char **)operator new(0xCu);
        if ( v8 )
        {
          *v8 = v5;
          v8[1] = 0;
          *((_BYTE *)v8 + 8) = 0;
        }
        else
        {
          v8 = 0;
        }
        if ( *v7 )
        {
          v7[1][1] = (char *)v8;
        }
        else
        {
          *v7 = v8;
          v7[2] = v8;
        }
        v9 = v7[3];
        v7[1] = v8;
        v10 = v33;
        v7[3] = (char **)((char *)v9 + 1);
        v33 = v10 + 1;
      }
      while ( v10 + 1 < v36 );
      v2 = a2;
    }
    v11 = this[212];
    while ( v11 )
    {
      v12 = (_DWORD *)v11;
      v13 = *(_BYTE *)(v11 + 12) == 0;
      v11 = *(_DWORD *)(v11 + 4);
      i = v12;
      if ( !v13 && *v12 )
      {
        sub_4DBCC0(1);
        v12 = i;
      }
      sub_5BE8AE(v12);
    }
    this[212] = 0;
    this[213] = 0;
    this[214] = 0;
    this[215] = 0;
    v30 = 0;
    sub_57A3D0(&v30, 1u);
    v33 = 0;
    if ( v30 )
    {
      do
      {
        v14 = operator new(0xCu);
        if ( v14 )
        {
          v14[1] = 0;
          v14[2] = -1;
          v15 = v14;
        }
        else
        {
          v15 = 0;
        }
        sub_4D31A0(v15, v2);
        if ( v15 )
        {
          v16 = operator new(0x10u);
          if ( v16 )
          {
            *v16 = v15;
            v16[1] = 0;
            v16[2] = 0;
            *((_BYTE *)v16 + 12) = 1;
          }
          else
          {
            v16 = 0;
          }
          if ( this[212] )
          {
            *(_DWORD *)(this[213] + 4) = v16;
            v16[2] = this[213];
          }
          else
          {
            this[212] = v16;
            this[214] = v16;
          }
          this[213] = v16;
          ++this[215];
        }
        ++v33;
      }
      while ( v33 < v30 );
    }
    sub_57A3D0(this + 512, 4u);
    sub_57A3D0(this + 513, 4u);
    sub_57A3D0(this + 514, 4u);
    sub_4D5820(this);
    v17 = this[512] <= 0;
    v33 = 0;
    if ( !v17 )
    {
      v18 = this + 12;
      for ( i = this + 12; ; v18 = i )
      {
        v19 = 0;
        sub_414470(v18);
        v20 = v18[2];
        if ( v20 )
        {
          v19 = *(_DWORD *)v20;
          v29 = *(_DWORD *)v20;
          *(_BYTE *)(v20 + 8) = 0;
          v21 = sub_4DAD10(v29, 1);
          v18 = i;
          if ( !v21 )
            v19 = 0;
        }
        if ( !v19 )
        {
          sub_4DBAC0(this + 8);
          v19 = sub_4DB530(v18);
        }
        sub_4D3400((_DWORD *)v19, a2);
        if ( v19 )
        {
          v22 = (int *)operator new(0x10u);
          if ( v22 )
          {
            *v22 = v19;
            v22[1] = 0;
            v22[2] = 0;
            *((_BYTE *)v22 + 12) = 0;
          }
          else
          {
            v22 = 0;
          }
          if ( this[233] )
          {
            *(_DWORD *)(this[234] + 4) = v22;
            v22[2] = this[234];
          }
          else
          {
            this[233] = v22;
            this[235] = v22;
          }
          this[234] = v22;
          ++this[236];
        }
        v23 = 0;
        if ( *(_WORD *)(v19 + 8) )
        {
          do
          {
            sub_4D3340(a2);
            ++v23;
          }
          while ( v23 < *(unsigned __int16 *)(v19 + 8) );
        }
        v24 = this[512];
        if ( ++v33 >= v24 )
          break;
      }
    }
    this[515] = 0;
    this[516] = 0;
    v25 = (float **)this[233];
    this[235] = v25;
    if ( v25 )
    {
      v26 = *v25;
      if ( v26 )
      {
        v27 = *v26;
        *((float *)this + 515) = *v26;
        *((float *)this + 516) = v27 + *((float *)this + 514);
      }
    }
    return 1;
  }
  return result;
}
