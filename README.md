## About

In this project, we'll code a simple 2D game to get familiar with the mlx library and UI in general.

Bu projede, mlx kitaplığına ve genel olarak kullanıcı arayüzüne aşina olmak için basit bir 2B oyun kodlayacağız.

---

![ezgif com-video-to-gif](https://user-images.githubusercontent.com/114104599/233431332-e640416b-691d-4087-b6bc-8c2be6cbb6dd.gif)

## Bonus part hakkında

Projenin bonus kısmını yaparken kafama takılan bazı konuları nasıl çözdügüm ve optimizasyonu nasıl sağladığım hakkında size bilgi vereceğim.

### Animation

Animasyonu ilk başta aklıma gelen en basit yöntemle yani usleep veya döngüleri kullanarak yapmayı denedim fakat başarısız oldu.

```c
mlx_loop_hook(data->mlx, ft_loop_function, data);
```

bu mlx fonksiyonunda mlx fonksiyonu sürekli olarak ana programdan bağımsız şekilde loopa girmektedir ana programdan bağımsız şekilde derken şunu kast ediyorum, çalışan bir adet program var ve bu programı mlx kütüphanesinin fonksiyonunu kullanmadan herhangi bir şekilde loopa soktugumuzda bütün program loopa girdigi için veya herhangi bir sleep fonksiyonu kullandıgımızda bütün program belirli bir saniye durdugu için karakterin animasyonunu, collectablelerin animasyonunu ve düşmanın animasyonunu eş zamanlı kontrol etmek müthiş bir optimizasyon sıkıntısına yol açıyodu. mlx_loop_hook fonksiyonunun programdan bağımsız bir şekilde sürekli loopa girdigi için her bir animasyonu ve spriteyi ayri ayri kontrol etme imkani sağlayabildim.

---

### Character sprites

Oyuncu W A S D tuşlarından birine bastığında 64*64 piksel olarak yerleştirilmiş karakterin o anki konumuna (+-)64 ekleyerek hareket işlemlerini yapıyorum, peki nasıl yürüyor ? Sürekli çalışan loopumuz karakterin ‘D’ tuşuna veya ‘A’ tuşuna basıp basmadığının true ve false değer olarak kontrol ediyor. Oyuncu olarak ‘D’ tuşuna bastığınız ve düşmanın sağa doğru bir adım atmasını istiyoruz bunun için karakter sağa giderken (karakterin konumu +- 32)’ye (2 64*64 pikselli karenin ortasi) karakterin yürürken ki halinin fotografını bastırıp ardından karakterin hareketi tamamlandığında ve oyuncu elini D tuşundan çekitiginde struct yapımın içerisindeki  oyuncunun hangi yöndeki tuşa bastıgının değerini true false cinsinden kontrol eden değişkeni tekrardan false değerine çekiyor bu sayede karakterimizin sağ ve sol adımlarını yerleştirdim.

---

---

---

Daha önce kodladığım **get_next_line** fonksiyonu ve **ft_printf** fonksiyonunu projemde yer almakta. İstediğimiz gibi düzenleyebildiğimiz map’i get_next_line fonksiyonunu kullanarak okuyorum ve struct yapısında ‘char **map’ dizisinin içerisine satır ve sütün olacak şekilde map’i okuyorum.

Yüzeysel olarak map’i nasıl okudugumun üstünden geçtigime göre biraz mlx kütüphanesinin içeriğinden bahsedebilirim.

---

- **mlx_init()** fonksiyonu, bizim için dogrudan ekran kartı ile bağlantı kuracak. bu fonkisyon void * return eder.

```c
**#include <mlx.h>

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();mlx_init()
}**
```

Bu kodu çalıştırdığınızda ekranda hiçbir şeyin oluşmadıgını göreceksiniz. Bu nedenle üzerine resimleri bastırabileceğimiz bir pencere oluşturmamız gerekecek. şimdi ise yeni kapatana kadar çalışmaya devam edecek bir pencere oluşturmayi deneyelim, isterseniz CTRL+C ile kapatabilirsiniz.

---

Pencere oluşturabilmek için yeni bir mlx fonksiyonu kullanmamız gerekiyor.

- **mlx_new_window()** fonksiyonu, öncesinde mlx init ile ekran kartı ile baglantı kurduktan sonra ekrana bir pencere oluşturmasını ve fonksiyonun parametreleri sayesinde bu oluşturdugumuz pencerenin boyutunu, pencerenin ismini belirleyebiliyoruz. Daha sonra penceremizin kapanmaması için **mlx_loop()** fonksiyonunu kullanmamız gerekiyor. Şimdi birlikte genişliği 1920, yüksekliği 1080 olan bir pencere oluşturalım ve penceremizin ismine de “Karabaş” ismini verelim.

```c
#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Karabas");
	mlx_loop(mlx);
}
```

---

- **mlx_xpm_file_to_image()** XPM dosyasi halindeki görüntüyü resime çevirme işlemi yapar.

```c
img[1] = mlx_xpm_file_to_image(data->mlx,"./srcs/img/character.xpm", &x, &y);
```

- **mlx_put_image_to_window()** Ekrana resimleri basmak için kullanılır. İlk parametre olarak sizden mlx adresinizi (mlx) bir sonraki parametrede hangi pencereye resimi basacağınızı (mlx_win) ve resimin pencerede hangi x y konumlarında basılacağını belirtmenizi ister.

```c
mlx_put_image_to_window(mlx, mlx_win, img[1], x, y);
```

**mlx_hook()** Belirli haraketlerimizi (mouse, key, etc.. events) yakalamanızı sağlar.

---

