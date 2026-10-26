char __thiscall sub_4B6C90(int this, int a2)
{
  int v2; // esi
  char result; // al
  _BYTE *v5; // ebp
  int v6; // eax
  _DWORD *v7; // esi
  int v8; // eax
  int v9; // ebp
  int v10; // eax
  int v11; // ebp
  _DWORD *v12; // eax
  bool v13; // zf
  _DWORD *v14; // eax
  void *v15; // ebp
  int v16; // eax
  bool v17; // cc
  _DWORD *v18; // ebp
  int v19; // esi
  int v20; // eax
  char v21; // al
  int v22; // eax
  int v23; // ebp
  int v24; // ecx
  float **v25; // eax
  float *v26; // eax
  double v27; // st7
  _BYTE *v28; // [esp-Ch] [ebp-12Ch]
  int v29; // [esp-Ch] [ebp-12Ch]
  unsigned __int8 v30; // [esp+Dh] [ebp-113h] BYREF
  unsigned __int8 v31; // [esp+Eh] [ebp-112h] BYREF
  unsigned __int8 v32; // [esp+Fh] [ebp-111h] BYREF
  int v33; // [esp+10h] [ebp-110h]
  _DWORD *i; // [esp+14h] [ebp-10Ch]
  int v35; // [esp+18h] [ebp-108h] BYREF
  int v36; // [esp+1Ch] [ebp-104h] BYREF
  _BYTE v37[256]; // [esp+20h] [ebp-100h] BYREF

  v2 = a2;
  result = sub_4B8090(a2);
  if ( result )
  {
    sub_566C00(&v35, 4);
    sub_566C00(v37, v35);
    v37[v35] = 0;
    sub_566650(v37);
    sub_566C00(&v35, 4);
    sub_566C00(v37, v35);
    v37[v35] = 0;
    sub_566650(v37);
    v31 = 0;
    sub_566C00(&v31, 1);
    *(_DWORD *)(this + 3868) = v31;
    v32 = 0;
    sub_566C00(&v32, 1);
    *(_DWORD *)(this + 3872) = v32;
    sub_4B5E50((_DWORD *)this);
    sub_566C00(&v36, 4);
    v33 = 0;
    if ( v36 > 0 )
    {
      do
      {
        v5 = 0;
        sub_4BA780(this + 16);
        v6 = *(_DWORD *)(this + 24);
        if ( v6 )
        {
          v5 = *(_BYTE **)v6;
          v28 = *(_BYTE **)v6;
          *(_BYTE *)(v6 + 8) = 0;
          if ( !(unsigned __int8)sub_4BA830(v28, 1) )
            v5 = 0;
        }
        if ( !v5 )
        {
          sub_4BAFC0(this);
          v5 = (_BYTE *)sub_4BB0C0(this + 16);
        }
        sub_4B5040(v5, a2);
        v7 = (_DWORD *)(this + 16 * ((unsigned __int8)*v5 + 4));
        v8 = sub_587C03(12);
        if ( v8 )
        {
          *(_DWORD *)v8 = v5;
          *(_DWORD *)(v8 + 4) = 0;
          *(_BYTE *)(v8 + 8) = 0;
        }
        else
        {
          v8 = 0;
        }
        if ( *v7 )
        {
          *(_DWORD *)(v7[1] + 4) = v8;
        }
        else
        {
          *v7 = v8;
          v7[2] = v8;
        }
        v9 = v7[3];
        v7[1] = v8;
        v10 = v33;
        v7[3] = v9 + 1;
        v33 = v10 + 1;
      }
      while ( v10 + 1 < v36 );
      v2 = a2;
    }
    v11 = *(_DWORD *)(this + 1728);
    while ( v11 )
    {
      v12 = (_DWORD *)v11;
      v13 = *(_BYTE *)(v11 + 12) == 0;
      v11 = *(_DWORD *)(v11 + 4);
      i = v12;
      if ( !v13 && *v12 )
      {
        sub_4BB460(1);
        v12 = i;
      }
      sub_587BCF(v12);
    }
    *(_DWORD *)(this + 1728) = 0;
    *(_DWORD *)(this + 1732) = 0;
    *(_DWORD *)(this + 1736) = 0;
    *(_DWORD *)(this + 1740) = 0;
    v30 = 0;
    sub_566C00(&v30, 1);
    v33 = 0;
    if ( v30 )
    {
      do
      {
        v14 = (_DWORD *)sub_587C03(12);
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
        sub_4B4250(v15, v2);
        if ( v15 )
        {
          v16 = sub_587C03(16);
          if ( v16 )
          {
            *(_DWORD *)v16 = v15;
            *(_DWORD *)(v16 + 4) = 0;
            *(_DWORD *)(v16 + 8) = 0;
            *(_BYTE *)(v16 + 12) = 1;
          }
          else
          {
            v16 = 0;
          }
          if ( *(_DWORD *)(this + 1728) )
          {
            *(_DWORD *)(*(_DWORD *)(this + 1732) + 4) = v16;
            *(_DWORD *)(v16 + 8) = *(_DWORD *)(this + 1732);
          }
          else
          {
            *(_DWORD *)(this + 1728) = v16;
            *(_DWORD *)(this + 1736) = v16;
          }
          *(_DWORD *)(this + 1732) = v16;
          ++*(_DWORD *)(this + 1740);
        }
        ++v33;
      }
      while ( v33 < v30 );
    }
    sub_566C00(this + 3876, 4);
    sub_566C00(this + 3880, 4);
    sub_566C00(this + 3884, 4);
    sub_4B5F60((_DWORD *)this);
    v17 = *(_DWORD *)(this + 3876) <= 0;
    v33 = 0;
    if ( !v17 )
    {
      v18 = (_DWORD *)(this + 48);
      for ( i = (_DWORD *)(this + 48); ; v18 = i )
      {
        v19 = 0;
        sub_4BA780(v18);
        v20 = v18[2];
        if ( v20 )
        {
          v19 = *(_DWORD *)v20;
          v29 = *(_DWORD *)v20;
          *(_BYTE *)(v20 + 8) = 0;
          v21 = sub_4BB6B0(v29, 1);
          v18 = i;
          if ( !v21 )
            v19 = 0;
        }
        if ( !v19 )
        {
          sub_4BB200(this + 32);
          v19 = sub_4BACF0(v18);
        }
        sub_4B44A0((_DWORD *)v19, a2);
        if ( v19 )
        {
          v22 = sub_587C03(16);
          if ( v22 )
          {
            *(_DWORD *)v22 = v19;
            *(_DWORD *)(v22 + 4) = 0;
            *(_DWORD *)(v22 + 8) = 0;
            *(_BYTE *)(v22 + 12) = 0;
          }
          else
          {
            v22 = 0;
          }
          if ( *(_DWORD *)(this + 1812) )
          {
            *(_DWORD *)(*(_DWORD *)(this + 1816) + 4) = v22;
            *(_DWORD *)(v22 + 8) = *(_DWORD *)(this + 1816);
          }
          else
          {
            *(_DWORD *)(this + 1812) = v22;
            *(_DWORD *)(this + 1820) = v22;
          }
          *(_DWORD *)(this + 1816) = v22;
          ++*(_DWORD *)(this + 1824);
        }
        v23 = 0;
        if ( *(_WORD *)(v19 + 8) )
        {
          do
          {
            sub_4B43E0(a2);
            ++v23;
          }
          while ( v23 < *(unsigned __int16 *)(v19 + 8) );
        }
        v24 = *(_DWORD *)(this + 3876);
        if ( ++v33 >= v24 )
          break;
      }
    }
    *(_DWORD *)(this + 3888) = 0;
    *(_DWORD *)(this + 3892) = 0;
    v25 = *(float ***)(this + 1812);
    *(_DWORD *)(this + 1820) = v25;
    if ( v25 )
    {
      v26 = *v25;
      if ( v26 )
      {
        v27 = *v26;
        *(float *)(this + 3888) = *v26;
        *(float *)(this + 3892) = v27 + *(float *)(this + 3884);
      }
    }
    return 1;
  }
  return result;
}
