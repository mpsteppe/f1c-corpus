__int64 __thiscall sub_50A150(int this)
{
  _DWORD *v2; // eax
  char *v3; // eax
  _DWORD *v4; // eax
  char *v5; // eax
  double v6; // st7
  double v7; // st7
  int v8; // edx
  int v9; // eax
  int v10; // ecx
  _DWORD *v11; // eax
  char *v12; // eax
  _DWORD *v13; // eax
  char *v14; // eax
  double v15; // st7
  double v16; // st7
  float v17; // eax
  int v18; // ebx
  int v19; // edi
  int v20; // ebp
  _DWORD *v21; // eax
  char *v22; // eax
  _DWORD *v23; // eax
  char *v24; // eax
  __int64 result; // rax
  float v26; // [esp+4h] [ebp-Ch]
  float v27; // [esp+4h] [ebp-Ch]
  float v28; // [esp+8h] [ebp-8h]
  float v29; // [esp+8h] [ebp-8h]
  float v30; // [esp+Ch] [ebp-4h]
  float v31; // [esp+Ch] [ebp-4h]

  v26 = 70.0;
  v30 = (float)*(int *)(this + 10920);
  if ( sub_616840("Difficulty") )
  {
    if ( sub_616610(*(_DWORD *)(this + 11784)) )
    {
      v2 = (_DWORD *)sub_616630("AIStrength");
      if ( v2 )
      {
        v3 = sub_48D380(v2);
        v26 = atof(v3);
      }
    }
  }
  v4 = (_DWORD *)sub_616840("AIStrength");
  if ( v4 )
  {
    v5 = sub_48D380(v4);
    v6 = atof(v5);
  }
  else
  {
    v6 = 0.0;
  }
  if ( v6 > v26 )
    v26 = v6;
  v7 = v30;
  if ( v30 >= (double)v26 )
  {
    if ( v7 > 120.0 )
      v7 = 120.0;
  }
  else
  {
    v7 = v26;
  }
  v8 = *(_DWORD *)(this + 10932);
  *(_DWORD *)(this + 10920) = (unsigned __int64)v7;
  v9 = *(_DWORD *)(this + 10928);
  v10 = *(_DWORD *)(this + 10920);
  if ( v10 >= v9 )
  {
    if ( v10 > v8 )
      *(_DWORD *)(this + 10920) = v8;
  }
  else
  {
    *(_DWORD *)(this + 10920) = v9;
  }
  v27 = *(float *)(this + 10892);
  v28 = v27;
  v31 = *(float *)(this + 10884);
  if ( sub_616840("Difficulty") )
  {
    if ( sub_616610(*(_DWORD *)(this + 11784)) )
    {
      v11 = (_DWORD *)sub_616630("AIAggression");
      if ( v11 )
      {
        v12 = sub_48D380(v11);
        v27 = atof(v12);
      }
    }
  }
  v13 = (_DWORD *)sub_616840("AIRealism");
  if ( v13 )
  {
    v14 = sub_48D380(v13);
    v15 = atof(v14);
  }
  else
  {
    v15 = v28;
  }
  if ( v15 > v27 )
    v27 = v15;
  v16 = v31;
  v29 = *(float *)(this + 10896);
  if ( v31 >= (double)v27 )
  {
    if ( v16 > v29 )
      v16 = v29;
  }
  else
  {
    v16 = v27;
  }
  v17 = *(float *)(this + 10896);
  *(float *)(this + 10884) = v16;
  if ( *(float *)(this + 10892) <= (double)*(float *)(this + 10884) )
  {
    if ( *(float *)(this + 10884) > (double)v17 )
      *(float *)(this + 10884) = v17;
  }
  else
  {
    *(float *)(this + 10884) = *(float *)(this + 10892);
  }
  v18 = *(_DWORD *)(this + 10436);
  v19 = *(_DWORD *)(this + 10428);
  v20 = 0;
  if ( sub_616840("Difficulty") )
  {
    if ( sub_616610(*(_DWORD *)(this + 11784)) )
    {
      v21 = (_DWORD *)sub_616630("Damage");
      if ( v21 )
      {
        v22 = sub_48D380(v21);
        v18 = atol(v22);
      }
    }
  }
  v23 = (_DWORD *)sub_616840("Damage");
  if ( v23 )
  {
    v24 = sub_48D380(v23);
    v20 = atol(v24);
  }
  if ( v20 > v18 )
    v18 = v20;
  if ( v19 >= v18 )
  {
    if ( v19 > *(_DWORD *)(this + 10440) )
      v19 = *(_DWORD *)(this + 10440);
  }
  else
  {
    v19 = v18;
  }
  result = *(_QWORD *)(this + 10436);
  *(_DWORD *)(this + 10428) = v19;
  if ( v19 >= (int)result )
  {
    if ( v19 > SHIDWORD(result) )
      *(_DWORD *)(this + 10428) = HIDWORD(result);
  }
  else
  {
    *(_DWORD *)(this + 10428) = result;
  }
  return result;
}
