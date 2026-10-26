int sub_4EC220()
{
  int v0; // esi
  const CHAR **v1; // eax
  const CHAR *v2; // eax
  int v4; // [esp+0h] [ebp-8h]
  int v5; // [esp+4h] [ebp-4h]

  v0 = 1;
  if ( sub_532D20(&unk_B76270) )
  {
    v0 = 0;
    v1 = (const CHAR **)sub_535010(&unk_B76270);
    if ( v1 )
    {
      v2 = *v1;
      if ( !v2 )
        v2 = WindowName;
      sub_538860(&unk_BE1CFD, v2, v4, v5);
      sub_4EB610();
    }
  }
  return v0;
}
