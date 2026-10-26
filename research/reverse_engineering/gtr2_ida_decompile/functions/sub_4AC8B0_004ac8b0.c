int __thiscall sub_4AC8B0(float *this)
{
  const CHAR *v3; // eax
  int v4; // eax
  int *v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // [esp+0h] [ebp-22Ch]
  const CHAR *v9; // [esp+Ch] [ebp-220h]
  _DWORD v10[3]; // [esp+18h] [ebp-214h] BYREF
  char v11; // [esp+24h] [ebp-208h] BYREF

  if ( byte_B71CF0 )
  {
    (*(void (__thiscall **)(float *, int))(*(_DWORD *)this + 36))(this, 1);
    (*(void (__thiscall **)(float *, _DWORD))(*(_DWORD *)this + 40))(this, 0);
    sub_4DF3F0(0);
    return 0;
  }
  else
  {
    if ( this[74] < 0.0 )
    {
      (*(void (__thiscall **)(float *, _DWORD))(*(_DWORD *)this + 36))(this, 0);
      (*(void (__thiscall **)(float *, int))(*(_DWORD *)this + 40))(this, 1);
    }
    v10[1] = 512;
    v10[0] = &v11;
    sub_501CC0(&byte_B6F530, 1);
    sub_53BDE0(&unk_BE1CE0, v10);
    v3 = dword_B6F708;
    if ( !dword_B6F708 )
      v3 = WindowName;
    v9 = v3;
    sub_539FF0(&unk_BE1CE0);
    if ( *((_DWORD *)this + 75) != dword_BE1BD0 || !*((_DWORD *)this + 67) && this[74] < 0.0 )
    {
      (*(void (__thiscall **)(float *, _DWORD, const CHAR *))(*(_DWORD *)this + 40))(this, 0, v9);
      *((_DWORD *)this + 75) = dword_BE1BD0;
      this[74] = 0.5;
    }
    if ( dword_B6E198 )
    {
      if ( *((_DWORD *)this + 67) )
      {
        if ( dword_B6E070 )
        {
          v4 = sub_5DA9A0("ARMS", dword_B6E070);
          if ( v4 )
          {
            if ( *(int *)(v4 + 544) > 0 )
            {
              v5 = *(int **)(v4 + 532);
              if ( v5 )
              {
                v6 = *v5;
                if ( *v5 )
                {
                  v7 = sub_5F12D0(v6, "CATSTEER");
                  if ( v7 )
                  {
                    *(float *)&v8 = *(float *)(*(_DWORD *)(v7 + 28) + 24) * 0.5;
                    sub_5F1530(v6, v7, v8);
                  }
                }
              }
            }
          }
        }
      }
    }
    return 0;
  }
}
