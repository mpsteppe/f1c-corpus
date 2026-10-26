int __thiscall sub_4FBF60(char *this)
{
  char *v2; // edi
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  const CHAR **v6; // eax
  CHAR *v7; // eax
  char *v8; // edx
  CHAR v9; // cl
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  char *v15; // eax
  const char *v17; // eax
  char *v18; // eax
  char *v19; // [esp+0h] [ebp-15Ch]
  char *v20; // [esp+0h] [ebp-15Ch]
  char *v21; // [esp+8h] [ebp-154h]
  char *v22; // [esp+8h] [ebp-154h]
  char *v23; // [esp+8h] [ebp-154h]
  char *v24; // [esp+8h] [ebp-154h]
  char *v25; // [esp+8h] [ebp-154h]
  char *v26; // [esp+8h] [ebp-154h]
  char *v27; // [esp+8h] [ebp-154h]
  char *v28; // [esp+8h] [ebp-154h]
  char *v29; // [esp+8h] [ebp-154h]
  char *v30; // [esp+8h] [ebp-154h]
  int v31; // [esp+Ch] [ebp-150h]
  double v32; // [esp+14h] [ebp-148h]
  char Buffer[64]; // [esp+1Ch] [ebp-140h] BYREF
  char v34[256]; // [esp+5Ch] [ebp-100h] BYREF

  v32 = (double)*((int *)this + 43) * *((double *)this + 20) + *((double *)this + 19);
  if ( *((float *)this + 186) == 0.0 )
    Buffer[0] = 0;
  else
    sprintf(Buffer, "/%d", (unsigned int)(unsigned __int64)(*((float *)this + 186) * v32));
  if ( dword_B72454 == 1 )
    sprintf(this + 182, "%4.1f%s", v32 * 0.2641720372841846, Buffer);
  else
    sprintf(this + 182, "%d%s", (unsigned int)(unsigned __int64)(v32 + 0.5), Buffer);
  v2 = this + 246;
  v3 = 2;
  do
  {
    v4 = *(_DWORD *)(v2 - 10);
    if ( v4 > 0
      && (v5 = v4 - 1, v5 < *(_DWORD *)(*((_DWORD *)this + 166) + 16))
      && (v6 = (const CHAR **)sub_560800(v5)) != 0 )
    {
      v7 = (CHAR *)*v6;
      if ( !v7 )
        v7 = (CHAR *)WindowName;
      v8 = (char *)(v34 - v7);
      do
      {
        v9 = *v7;
        v7[(_DWORD)v8] = *v7;
        ++v7;
      }
      while ( v9 );
      v20 = sub_41D840(&byte_91CC38, v34);
      sprintf(v2, "%s", v20);
    }
    else
    {
      v19 = sub_41D840(&byte_91CC38, "No Change");
      sprintf(v2, "%s", v19);
    }
    v2 += 64;
    --v3;
  }
  while ( v3 );
  if ( *((_DWORD *)this + 106) == 1 )
  {
    v21 = sub_41D840(&byte_91CC38, "OK");
    sprintf(this + 438, "%s", v21);
  }
  else
  {
    v10 = "Replace";
    if ( !*((_DWORD *)this + 107) )
      v10 = "Do Not Replace";
    v22 = sub_41D840(&byte_91CC38, v10);
    sprintf(this + 438, "%s", v22);
  }
  if ( *((_DWORD *)this + 122) == 1 )
  {
    v23 = sub_41D840(&byte_91CC38, "OK");
    sprintf(this + 502, "%s", v23);
  }
  else
  {
    v11 = "Replace";
    if ( !*((_DWORD *)this + 123) )
      v11 = "Do Not Replace";
    v24 = sub_41D840(&byte_91CC38, v11);
    sprintf(this + 502, "%s", v24);
  }
  sprintf(this + 54, "%.8s", (const char *)(108 * *((_DWORD *)this + 11) + *(_DWORD *)this + 21656));
  if ( *((_DWORD *)this + 90) == 1 )
  {
    v25 = sub_41D840(&byte_91CC38, "OK");
    sprintf(this + 374, "%s", v25);
  }
  else
  {
    v12 = "Repair";
    if ( !*((_DWORD *)this + 91) )
      v12 = "Do Not Repair";
    v26 = sub_41D840(&byte_91CC38, v12);
    sprintf(this + 374, "%s", v26);
  }
  if ( *((_DWORD *)this + 138) == 1 )
  {
    v27 = sub_41D840(&byte_91CC38, "OK");
    sprintf(this + 566, "%s", v27);
  }
  else
  {
    v13 = "Replace";
    if ( !*((_DWORD *)this + 139) )
      v13 = "Do Not Replace";
    v28 = sub_41D840(&byte_91CC38, v13);
    sprintf(this + 566, "%s", v28);
  }
  if ( *((_DWORD *)this + 154) == 1 )
  {
    v29 = sub_41D840(&byte_91CC38, "OK");
    sprintf(this + 630, "%s", v29);
  }
  else
  {
    v14 = "Replace";
    if ( !*((_DWORD *)this + 155) )
      v14 = "Do Not Replace";
    v30 = sub_41D840(&byte_91CC38, v14);
    sprintf(this + 630, "%s", v30);
  }
  if ( *((_DWORD *)this + 26) == 1 )
  {
    v15 = sub_41D840(&byte_91CC38, off_6F3FD0);
    return sprintf(this + 118, "%s", v15);
  }
  else
  {
    v17 = (const char *)&off_6F9398;
    if ( !*((_DWORD *)this + 27) )
      v17 = (const char *)&unk_6F939C;
    v31 = *(_DWORD *)(*(_DWORD *)this + 19396);
    v18 = sub_41D840(&byte_91CC38, v17);
    return sprintf(this + 118, "%s/%d", v18, v31);
  }
}
