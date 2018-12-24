# Linux User Management

## Users

Add user:

    useradd -c "Full Name" username

Add user with custom group and custom default shell:

    useradd -s /bin/sh -g groupname username

Add/change password:

    passwd username

Set expiration date for account:

    usermod -e YYYY-MM-DD username

Set password expiration date:

    chage -l username

Examine hashed password:

    grep username /etc/passwd

Examine properties of user:

    id username

Change user ID:

    usermod -u 1600 username

Move to new group ID:

    usermod -g 999 username

Delete user:

    userdel -r username

## Groups

Create group:

    groupadd groupname

Examine group entry:

    grep groupname /etc/group

Create system group:

    groupadd -r groupname

Change group ID:

    groupmod -g 1600 groupname

Rename group:

    groupmod -n oldgroupname newgroupname

Delete group:

    groupdel groupname
