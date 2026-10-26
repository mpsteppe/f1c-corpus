int __thiscall sub_40E9D0(int *this, char *String2)
{
  int v3; // edi
  int v4; // eax
  int v5; // edi
  int v6; // eax
  const char *v7; // eax
  __int64 v8; // rax
  int v9; // ebx
  int v10; // edi
  int v11; // eax
  int v12; // esi
  const char *v13; // eax

  if ( _strcmpi(aRacewinnerbonu, String2) )
  {
    v9 = sub_57AE50(String2);
    if ( v9 )
    {
      v10 = *this;
      v11 = (*(int (__thiscall **)(int *))(*this + 36))(this);
      v12 = (*(int (__thiscall **)(int *, int))(v10 + 64))(this, v11);
      v13 = (const char *)sub_57A6D0(v9);
      return (__int64)(atof(v13) * (double)v12 + 0.5);
    }
LABEL_7:
    LODWORD(v8) = 0;
    return v8;
  }
  v3 = *this;
  v4 = (*(int (__thiscall **)(int *))(*this + 36))(this);
  v5 = (*(int (__thiscall **)(int *, int))(v3 + 64))(this, v4);
  if ( !sub_57AE50(aRacepursemulti) )
    goto LABEL_7;
  v6 = sub_57A700(0);
  if ( !v6 )
    goto LABEL_7;
  v7 = (const char *)sub_57A6D0(v6);
  return (__int64)(atof(v7) * (double)v5 + 0.5);
}
