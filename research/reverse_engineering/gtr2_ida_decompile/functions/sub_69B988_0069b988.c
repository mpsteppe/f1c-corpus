int __thiscall sub_69B988(_DWORD *this, int a2, int a3, int a4)
{
  int v5; // esi
  bool v6; // zf
  int i; // esi
  int v8; // ecx
  int v9; // eax
  _DWORD *v10; // eax
  _DWORD *v11; // eax
  _DWORD *v12; // ebx
  int v13; // eax
  _DWORD *v14; // eax
  _DWORD *v15; // esi
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int result; // eax
  int v26; // ebx
  int v27; // ecx
  int v28; // eax
  int v29; // eax
  int v30; // ebx
  int v31; // eax
  int v32; // [esp-8h] [ebp-6Ch]
  _DWORD *v33; // [esp-4h] [ebp-68h]
  _DWORD v34[8]; // [esp+Ch] [ebp-58h] BYREF
  int v35; // [esp+2Ch] [ebp-38h]
  int v36; // [esp+38h] [ebp-2Ch]
  int v37; // [esp+4Ch] [ebp-18h]
  int *v38; // [esp+50h] [ebp-14h] BYREF
  _DWORD *v39; // [esp+54h] [ebp-10h]
  int v40; // [esp+58h] [ebp-Ch]
  int v41; // [esp+5Ch] [ebp-8h]
  int v42; // [esp+60h] [ebp-4h]

  v38 = 0;
  v5 = sub_694F8F(this);
  v37 = v5;
  sub_67F449(v34);
  if ( !v5 || !a2 )
    return 0;
  v6 = (*(_BYTE *)(v5 + 16) & 0x40) == 0;
  v39 = *(_DWORD **)(v5 + 24);
  v42 = a2 + 16;
  if ( !v6 )
    sub_694B97((int)this, a2 + 16, 3047, "'%s': functions cannot be declared 'uniform'", *(const char **)(a2 + 24));
  if ( (*(_BYTE *)(v5 + 16) & 1) != 0 )
    sub_694B97((int)this, a2 + 16, 3006, "'%s': functions cannot be declared 'extern'", *(const char **)(a2 + 24));
  if ( !sub_695154(this, v39) )
    sub_694B97((int)this, a2 + 16, 3038, "'%s': function return value must be numeric", *(const char **)(a2 + 24));
  v40 = 0;
  for ( i = a3; i; i = *(_DWORD *)(i + 12) )
  {
    v8 = *(_DWORD *)(i + 8);
    if ( v8 && *(_DWORD *)(v8 + 4) == 6 )
    {
      v9 = *(_DWORD *)(i + 12);
      if ( v9 && *(_DWORD *)(*(_DWORD *)(v9 + 8) + 4) == 12 )
      {
        v40 = 1;
        i = v9;
      }
      else if ( v40 )
      {
        sub_694B97(
          (int)this,
          a2 + 16,
          3044,
          "'%s': missing default value for parameter '%s'",
          *(const char **)(a2 + 24),
          *(const char **)(*(_DWORD *)(v8 + 20) + 24));
      }
    }
  }
  v10 = (_DWORD *)sub_65B229(20);
  v40 = v10 ? (int)sub_67ED1B(v10, 0, 0, (int)"Stmts") : 0;
  if ( !v40 )
    return 0;
  v11 = (_DWORD *)sub_65B229(48);
  if ( v11 )
  {
    v12 = sub_67F0EF(v11, 2, 0, 0, 0);
    v41 = (int)v12;
  }
  else
  {
    v41 = 0;
    v12 = 0;
  }
  if ( !v12 )
    return 0;
  *(_DWORD *)(v40 + 8) = v12;
  v13 = sub_67ECC3(a2);
  v12[5] = v13;
  if ( !v13 )
    return 0;
  v14 = (_DWORD *)sub_65B229(64);
  v15 = v14 ? sub_67F351(v14) : 0;
  if ( !v15 )
    return 0;
  v16 = v37;
  v12[6] = v15;
  v15[6] = *(_DWORD *)(v16 + 16);
  v17 = *(_DWORD *)(v16 + 20);
  if ( v17 )
  {
    v18 = sub_67ECC3(v17);
    v15[7] = v18;
    if ( !v18 )
      return 0;
  }
  if ( v39 )
  {
    v19 = sub_67ECC3((int)v39);
    v15[8] = v19;
    if ( !v19 )
      return 0;
  }
  sub_694F9B(this, v15[8], 1);
  if ( a4 )
  {
    if ( !v15[8] )
    {
      sub_694B97((int)this, v42, 3076, "'%s': void function cannot have a semantic", *(const char **)(v42 + 8));
      a4 = 0;
    }
    if ( a4 )
    {
      v20 = sub_67ECC3(a4);
      v15[13] = v20;
      if ( v20 )
      {
        while ( 1 )
        {
          v21 = *(_DWORD *)(a4 + 8);
          if ( v21 )
          {
            if ( *(_DWORD *)(v21 + 4) == 3 )
            {
              v22 = sub_67ECC3(*(_DWORD *)(a4 + 8));
              v15[12] = v22;
              if ( !v22 )
                break;
            }
          }
          a4 = *(_DWORD *)(a4 + 12);
          if ( !a4 )
            goto LABEL_45;
        }
      }
      return 0;
    }
  }
LABEL_45:
  if ( a3 )
  {
    if ( *(_DWORD *)(a3 + 8) )
    {
      v23 = sub_67ECC3(a3);
      v15[9] = v23;
      if ( !v23 )
        return 0;
    }
  }
  v24 = sub_69974C(this, 2, (const char **)v42, v15[7], v15[9], *(_DWORD *)(this[4] + 32), 10, &a3, &v38);
  if ( v24 < 0 )
  {
    sub_694B97((int)this, v42, 3003, "redefinition of '%s'", *(_DWORD *)(v42 + 8));
    return 0;
  }
  v26 = a3;
  if ( v24 )
  {
    v33 = (_DWORD *)v15[8];
    v15[4] = this[22];
    v28 = sub_6951CB(this, v33);
    v15[5] = v28;
    this[22] += v28;
  }
  else
  {
    if ( !sub_695259((_DWORD *)v15[8], *(_DWORD **)(a3 + 32)) )
    {
      sub_694B97((int)this, v42, 3068, "'%s': function return value differs from prototype", *(_DWORD *)(v42 + 8));
      return 0;
    }
    v27 = v41;
    v15[4] = *(_DWORD *)(v26 + 16);
    v15[5] = *(_DWORD *)(v26 + 20);
    *(_DWORD *)(v27 + 36) = *(_DWORD *)(v38[2] + 24);
  }
  v34[4] = v15[4];
  v29 = v15[5];
  v34[7] = 0;
  v34[5] = v29;
  v34[6] = 3;
  v35 = sub_67ECC3(v15[8]);
  v36 = sub_67ECC3(a4);
  sub_694F9B(this, v35, 0);
  v15[11] = sub_699E09(this, a2, (int)v34);
  if ( !v26 )
  {
    v30 = this[4];
    v32 = v41;
    this[4] = *(_DWORD *)(v30 + 32);
    v31 = sub_6961D0(this, v32, 0);
    this[4] = v30;
    if ( v31 < 0 )
      return 0;
    ++this[21];
  }
  *(_DWORD *)(this[4] + 20) = *(_DWORD *)(v42 + 8);
  result = v40;
  this[6] = v15;
  return result;
}
