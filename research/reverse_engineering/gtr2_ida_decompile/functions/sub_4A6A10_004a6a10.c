int sub_4A6A10()
{
  char *v0; // eax
  char *v1; // eax
  char *v3; // eax
  const char *v4; // [esp+10h] [ebp-14h]
  char *v5; // [esp+10h] [ebp-14h]
  HKEY phkResult; // [esp+1Ch] [ebp-8h] BYREF
  HKEY hKey; // [esp+20h] [ebp-4h] BYREF

  v0 = sub_41D840(&byte_91CC38, "Please wait...");
  sub_4EB900(&unk_B6F134, v0);
  if ( !strcmp(&byte_B6E010, &byte_B6E020) )
  {
    v1 = (char *)dword_B7384C;
    if ( !dword_B7384C )
      v1 = (char *)WindowName;
    CINet::SetServerName((CINet *)dword_B6CBB0, v1);
    CINet::SetDifficulty((CINet *)dword_B6CBB0, dword_B72338);
    switch ( CINet::Register((CINet *)dword_B6CBB0, byte_B6DFF0, &byte_B6E010, byte_B6DFD0, &byte_B6E030) )
    {
      case 0:
        sub_4CD6D0("REGISTER_SUCCESSFUL");
        return 0;
      case 1:
        v4 = "Registration Failed: Could not connect to the server !";
        goto LABEL_21;
      case 2:
        v4 = "Registration Failed: Version check failed !";
        goto LABEL_21;
      case 3:
        v4 = "Registration Failed: User already exists, please try another UserName";
        goto LABEL_21;
      case 5:
        v3 = sub_41D840(&byte_91CC38, "Registration Failed: Invalid CD Key !");
        sub_615860(v3);
        if ( !RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB", &phkResult) )
          RegCloseKey(phkResult);
        if ( !RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB\\GTR2", &phkResult) )
          RegCloseKey(phkResult);
        if ( !RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB\\GTR2\\Keys", &phkResult) )
          RegCloseKey(phkResult);
        if ( !RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB\\GTR2\\Keys", &hKey) )
        {
          RegDeleteValueA(hKey, "SerialNumber");
          RegCloseKey(hKey);
        }
        sub_4CD6D0("JOIN FAILURE PAGE");
        return 0;
      case 6:
        v4 = "Registration Failed: General Failure !";
        goto LABEL_21;
      case 0xA:
        v4 = "Could not find server !";
LABEL_21:
        v5 = sub_41D840(off_16C9B18, v4);
        sub_615860(v5);
        break;
      default:
        return 0;
    }
  }
  else
  {
    sub_615860("Password Confirmation Failed!|Please re-enter passwords");
  }
  sub_4CD6D0("JOIN FAILURE PAGE");
  return 0;
}
