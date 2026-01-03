Step by step
1. User bakal dibawa ke menu utama untuk register atau login.
2. Jika user belum memiliki account dan mencoba login, maka tidak akan bisa masuk ke menu selanjutnya.
3. Saat user register, data user akan di save ke file, dan saat login, input dari user akan di cek dengan file baru kemudian bisa login
4. Di menu kedua, user bisa rent atau return car
5. Di option rent car, user bisa sort list mobil dari harga dan nama (ada 4, masing masing 2 ascending dan descending)
6. Untuk return car, nanti akan ditampilkan mobil mana yang user pinjam.
7. Sudah ada input validation untuk mencegah input diluar range.
8. Jika ingin logout dan keluar, tinggal memilih option back.


FOR ADMIN:
Ada mode admin di login yang bisa di akses dengan username "Admin" dan password "!2345"
Di mode admin, admin bisa :
1. Melihat list mobil
2. Menambah data mobil
3. Menghapus data mobil
4. Keluar


Untuk sorting hanya ada di login user dan bukan admin.

Dalam file carList, formatnya adalah :
Brand;tipe mobil; harga; status(1 = available, 0 = rented);user mana yang meminjam

Untuk file userList, formatnya adalah :
username;password
